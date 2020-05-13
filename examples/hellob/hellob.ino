#include <mrubyc.h>
#include <SDHCI.h>
SDClass SD;

#define MEMSIZE (1024*30)
static uint8_t mempool[MEMSIZE];

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
  uint8_t *buf = load_mrb("hello.mrb");
  mrbc_init(mempool, MEMSIZE);
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
