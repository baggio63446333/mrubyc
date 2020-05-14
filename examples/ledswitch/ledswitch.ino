#include <mrubyc.h>
#include <SDHCI.h>
SDClass SD;

#define MEMSIZE (1024*30)
static uint8_t mempool[MEMSIZE];

// pinMode
static void c_pin_mode(mrb_vm *vm, mrb_value *v, int argc)
{
  pinMode(GET_INT_ARG(1), GET_INT_ARG(2));
}

// digitalRead
static void c_digital_read(mrb_vm *vm, mrb_value *v, int argc)
{
  int val = digitalRead(GET_INT_ARG(1));
  SET_INT_RETURN(val);
}

// digitalWrite
static void c_digital_write(mrb_vm *vm, mrb_value *v, int argc)
{
  digitalWrite(GET_INT_ARG(1), GET_INT_ARG(2));
}

uint8_t *load_mrb(const char *filename)
{
  File file;
  size_t nbyte;
  uint8_t *buf;

  SD.begin();
  file = SD.open(filename);
  if (!file) {
    Serial.print(filename);
    Serial.println(" does not exist");
    return NULL;
  }
  nbyte = file.size();
  Serial.print("size=");
  Serial.println(nbyte);

  buf = (uint8_t*)malloc(nbyte);
  if (buf) {
    file.read(buf, nbyte);
  }
  return buf;
}

void unload_mrb(void *buf)
{
  free(buf);
}

void setup() {
  uint8_t *buf = load_mrb("ledswitch.mrb");
  mrbc_init(mempool, MEMSIZE);
  mrbc_define_method(0, mrbc_class_object, "pin_mode",      c_pin_mode);
  mrbc_define_method(0, mrbc_class_object, "digital_read",  c_digital_read);
  mrbc_define_method(0, mrbc_class_object, "digital_write", c_digital_write);
  if(NULL == mrbc_create_task( buf, 0 )){
    Serial.println("mrbc_create_task error");
    return;
  }
  unload_mrb(buf);
  mrbc_run();
}

void loop() {
  /* Start USB MSC */
  if (SD.beginUsbMsc()) {
    Serial.println("USB MSC Failure!");
  } else {
    Serial.println("*** USB MSC Prepared! ***");
    Serial.println("Insert SD and Connect Extension Board USB to PC.");
  }
  while (1) {
    usleep(1);
  }
}
