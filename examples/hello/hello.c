/* dumped in big endian order.
   use `mrbc -e` option for better performance on little endian CPU. */
#include <stdint.h>
extern const uint8_t code[];
const uint8_t
#if defined __GNUC__
__attribute__((aligned(4)))
#elif defined _MSC_VER
__declspec(align(4))
#endif
code[] = {
0x52,0x49,0x54,0x45,0x30,0x30,0x30,0x36,0x9a,0x78,0x00,0x00,0x00,0x62,0x4d,0x41,
0x54,0x5a,0x30,0x30,0x30,0x30,0x49,0x52,0x45,0x50,0x00,0x00,0x00,0x44,0x30,0x30,
0x30,0x32,0x00,0x00,0x00,0x60,0x00,0x01,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x0c,
0x10,0x01,0x4f,0x02,0x00,0x2e,0x01,0x00,0x01,0x37,0x01,0x67,0x00,0x00,0x00,0x01,
0x00,0x00,0x0c,0x48,0x65,0x6c,0x6c,0x6f,0x20,0x57,0x6f,0x72,0x6c,0x64,0x21,0x00,
0x00,0x00,0x01,0x00,0x04,0x70,0x75,0x74,0x73,0x00,0x45,0x4e,0x44,0x00,0x00,0x00,
0x00,0x08,
};
