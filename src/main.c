// Plot3 Chip
// by David Lloyd, March 2023.

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

char font8x8[128][8] = {
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0000 (nul)
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0001
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0002
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0003
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0004
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0005
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0006
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0007
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0008
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0009
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000A
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000B
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000C
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000D
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000E
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000F
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0010
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0011
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0012
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0013
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0014
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0015
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0016
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0017
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0018
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0019
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001A
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001B
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001C
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001D
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001E
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001F
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0020 (space)
  { 0x18, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x18, 0x00},   // U+0021 (!)
  { 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0022 (")
  { 0x36, 0x36, 0x7F, 0x36, 0x7F, 0x36, 0x36, 0x00},   // U+0023 (#)
  { 0x0C, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x0C, 0x00},   // U+0024 ($)
  { 0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00},   // U+0025 (%)
  { 0x1C, 0x36, 0x1C, 0x6E, 0x3B, 0x33, 0x6E, 0x00},   // U+0026 (&)
  { 0x06, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0027 (')
  { 0x18, 0x0C, 0x06, 0x06, 0x06, 0x0C, 0x18, 0x00},   // U+0028 (()
  { 0x06, 0x0C, 0x18, 0x18, 0x18, 0x0C, 0x06, 0x00},   // U+0029 ())
  { 0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00},   // U+002A (*)
  { 0x00, 0x0C, 0x0C, 0x3F, 0x0C, 0x0C, 0x00, 0x00},   // U+002B (+)
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x06},   // U+002C (,)
  { 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00},   // U+002D (-)
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00},   // U+002E (.)
  { 0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00},   // U+002F (/)
  { 0x3E, 0x63, 0x73, 0x7B, 0x6F, 0x67, 0x3E, 0x00},   // U+0030 (0)
  { 0x0C, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x3F, 0x00},   // U+0031 (1)
  { 0x1E, 0x33, 0x30, 0x1C, 0x06, 0x33, 0x3F, 0x00},   // U+0032 (2)
  { 0x1E, 0x33, 0x30, 0x1C, 0x30, 0x33, 0x1E, 0x00},   // U+0033 (3)
  { 0x38, 0x3C, 0x36, 0x33, 0x7F, 0x30, 0x78, 0x00},   // U+0034 (4)
  { 0x3F, 0x03, 0x1F, 0x30, 0x30, 0x33, 0x1E, 0x00},   // U+0035 (5)
  { 0x1C, 0x06, 0x03, 0x1F, 0x33, 0x33, 0x1E, 0x00},   // U+0036 (6)
  { 0x3F, 0x33, 0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x00},   // U+0037 (7)
  { 0x1E, 0x33, 0x33, 0x1E, 0x33, 0x33, 0x1E, 0x00},   // U+0038 (8)
  { 0x1E, 0x33, 0x33, 0x3E, 0x30, 0x18, 0x0E, 0x00},   // U+0039 (9)
  { 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x00},   // U+003A (:)
  { 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x06},   // U+003B (;)
  { 0x18, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x18, 0x00},   // U+003C (<)
  { 0x00, 0x00, 0x3F, 0x00, 0x00, 0x3F, 0x00, 0x00},   // U+003D (=)
  { 0x06, 0x0C, 0x18, 0x30, 0x18, 0x0C, 0x06, 0x00},   // U+003E (>)
  { 0x1E, 0x33, 0x30, 0x18, 0x0C, 0x00, 0x0C, 0x00},   // U+003F (?)
  { 0x3E, 0x63, 0x7B, 0x7B, 0x7B, 0x03, 0x1E, 0x00},   // U+0040 (@)
  { 0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00},   // U+0041 (A)
  { 0x3F, 0x66, 0x66, 0x3E, 0x66, 0x66, 0x3F, 0x00},   // U+0042 (B)
  { 0x3C, 0x66, 0x03, 0x03, 0x03, 0x66, 0x3C, 0x00},   // U+0043 (C)
  { 0x1F, 0x36, 0x66, 0x66, 0x66, 0x36, 0x1F, 0x00},   // U+0044 (D)
  { 0x7F, 0x46, 0x16, 0x1E, 0x16, 0x46, 0x7F, 0x00},   // U+0045 (E)
  { 0x7F, 0x46, 0x16, 0x1E, 0x16, 0x06, 0x0F, 0x00},   // U+0046 (F)
  { 0x3C, 0x66, 0x03, 0x03, 0x73, 0x66, 0x7C, 0x00},   // U+0047 (G)
  { 0x33, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x33, 0x00},   // U+0048 (H)
  { 0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},   // U+0049 (I)
  { 0x78, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E, 0x00},   // U+004A (J)
  { 0x67, 0x66, 0x36, 0x1E, 0x36, 0x66, 0x67, 0x00},   // U+004B (K)
  { 0x0F, 0x06, 0x06, 0x06, 0x46, 0x66, 0x7F, 0x00},   // U+004C (L)
  { 0x63, 0x77, 0x7F, 0x7F, 0x6B, 0x63, 0x63, 0x00},   // U+004D (M)
  { 0x63, 0x67, 0x6F, 0x7B, 0x73, 0x63, 0x63, 0x00},   // U+004E (N)
  { 0x1C, 0x36, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x00},   // U+004F (O)
  { 0x3F, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x0F, 0x00},   // U+0050 (P)
  { 0x1E, 0x33, 0x33, 0x33, 0x3B, 0x1E, 0x38, 0x00},   // U+0051 (Q)
  { 0x3F, 0x66, 0x66, 0x3E, 0x36, 0x66, 0x67, 0x00},   // U+0052 (R)
  { 0x1E, 0x33, 0x07, 0x0E, 0x38, 0x33, 0x1E, 0x00},   // U+0053 (S)
  { 0x3F, 0x2D, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},   // U+0054 (T)
  { 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3F, 0x00},   // U+0055 (U)
  { 0x33, 0x33, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00},   // U+0056 (V)
  { 0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00},   // U+0057 (W)
  { 0x63, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63, 0x00},   // U+0058 (X)
  { 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x0C, 0x1E, 0x00},   // U+0059 (Y)
  { 0x7F, 0x63, 0x31, 0x18, 0x4C, 0x66, 0x7F, 0x00},   // U+005A (Z)
  { 0x1E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1E, 0x00},   // U+005B ([)
  { 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x40, 0x00},   // U+005C (\)
  { 0x1E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1E, 0x00},   // U+005D (])
  { 0x08, 0x1C, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00},   // U+005E (^)
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},   // U+005F (_)
  { 0x0C, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0060 (`)
  { 0x00, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x6E, 0x00},   // U+0061 (a)
  { 0x07, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00},   // U+0062 (b)
  { 0x00, 0x00, 0x1E, 0x33, 0x03, 0x33, 0x1E, 0x00},   // U+0063 (c)
  { 0x38, 0x30, 0x30, 0x3e, 0x33, 0x33, 0x6E, 0x00},   // U+0064 (d)
  { 0x00, 0x00, 0x1E, 0x33, 0x3f, 0x03, 0x1E, 0x00},   // U+0065 (e)
  { 0x1C, 0x36, 0x06, 0x0f, 0x06, 0x06, 0x0F, 0x00},   // U+0066 (f)
  { 0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x1F},   // U+0067 (g)
  { 0x07, 0x06, 0x36, 0x6E, 0x66, 0x66, 0x67, 0x00},   // U+0068 (h)
  { 0x0C, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},   // U+0069 (i)
  { 0x30, 0x00, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E},   // U+006A (j)
  { 0x07, 0x06, 0x66, 0x36, 0x1E, 0x36, 0x67, 0x00},   // U+006B (k)
  { 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},   // U+006C (l)
  { 0x00, 0x00, 0x33, 0x7F, 0x7F, 0x6B, 0x63, 0x00},   // U+006D (m)
  { 0x00, 0x00, 0x1F, 0x33, 0x33, 0x33, 0x33, 0x00},   // U+006E (n)
  { 0x00, 0x00, 0x1E, 0x33, 0x33, 0x33, 0x1E, 0x00},   // U+006F (o)
  { 0x00, 0x00, 0x3B, 0x66, 0x66, 0x3E, 0x06, 0x0F},   // U+0070 (p)
  { 0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x78},   // U+0071 (q)
  { 0x00, 0x00, 0x3B, 0x6E, 0x66, 0x06, 0x0F, 0x00},   // U+0072 (r)
  { 0x00, 0x00, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x00},   // U+0073 (s)
  { 0x08, 0x0C, 0x3E, 0x0C, 0x0C, 0x2C, 0x18, 0x00},   // U+0074 (t)
  { 0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x6E, 0x00},   // U+0075 (u)
  { 0x00, 0x00, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00},   // U+0076 (v)
  { 0x00, 0x00, 0x63, 0x6B, 0x7F, 0x7F, 0x36, 0x00},   // U+0077 (w)
  { 0x00, 0x00, 0x63, 0x36, 0x1C, 0x36, 0x63, 0x00},   // U+0078 (x)
  { 0x00, 0x00, 0x33, 0x33, 0x33, 0x3E, 0x30, 0x1F},   // U+0079 (y)
  { 0x00, 0x00, 0x3F, 0x19, 0x0C, 0x26, 0x3F, 0x00},   // U+007A (z)
  { 0x38, 0x0C, 0x0C, 0x07, 0x0C, 0x0C, 0x38, 0x00},   // U+007B ({)
  { 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00},   // U+007C (|)
  { 0x07, 0x0C, 0x0C, 0x38, 0x0C, 0x0C, 0x07, 0x00},   // U+007D (})
  { 0x6E, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+007E (~)
  { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}    // U+007F
};

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
} rgba_t;

typedef struct {
  pin_t pin_AD0;
  pin_t pin_AD1;
  pin_t pin_AD2;
  pin_t pin_AD3;
  uint32_t sampletime_attr;
  uint32_t trigger_attr;
  buffer_t framebuffer;
  uint32_t fb_w;
  uint32_t fb_h;
  uint32_t serial_h;
  uint32_t serial_x;
  uint32_t serial_y;
  float sample_ad0;
  float sample_last_ad0;
  float sample_ad1;
  float sample_last_ad1;
  float sample_ad2;
  float sample_last_ad2;
  float sample_max0;
  float sample_min0;
  float sample_max1;
  float sample_min1;
  float sample_max2;
  float sample_min2;
  uint32_t sample_us;
  uint32_t capture_ms;
  uint32_t plot_h;
  uint32_t plot_x;
  uint32_t plot_y0;
  uint32_t plot_py0;
  uint32_t plot_y1;
  uint32_t plot_py1;
  uint32_t plot_y2;
  uint32_t plot_py2;
  rgba_t white;
  rgba_t green;
  rgba_t background;
  timer_t timer;
  uint8_t timer_count;
} chip_state_t;

static void chip_timer_event(void *user_data);
static void draw_plot(chip_state_t *chip);
static void draw_string(chip_state_t *chip);
static void fill_string(chip_state_t *chip);
static void fill_plot(chip_state_t *chip);

void chip_init(void) {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  chip->pin_AD0 = pin_init("AD0", ANALOG);
  chip->pin_AD1 = pin_init("AD1", ANALOG);
  chip->pin_AD2 = pin_init("AD2", ANALOG);
  chip->pin_AD3 = pin_init("AD3", ANALOG);
  chip->sampletime_attr = attr_init("sampletime", 100);
  chip->trigger_attr = attr_init("trigger", 1);

  chip->white = (rgba_t) {
    .r = 0xff, .g = 0xff, .b = 0xff, .a = 0xff
  };
  chip->green = (rgba_t) {
    .r = 0x08, .g = 0x7f, .b = 0x45, .a = 0xff
  };
  chip->background = (rgba_t) {
    .r = 0xf7, .g = 0xf7, .b = 0xf7, .a = 0xff
  };

  chip->sample_max0 = 0.0;
  chip->sample_min0 = 5.0;
  chip->sample_max1 = 0.0;
  chip->sample_min1 = 5.0;
  chip->sample_max2 = 0.0;
  chip->sample_min2 = 5.0;
  chip->serial_x = 0;
  chip->serial_y = 0;
  chip->plot_x = 0;
  chip->plot_y0 = 0;
  chip->plot_py0 = 0;
  chip->plot_y1 = 24;
  chip->plot_py1 = 24;
  chip->plot_y2 = 48;
  chip->plot_py2 = 48;
  chip->serial_h = 36;

  chip->framebuffer = framebuffer_init(&chip->fb_w, &chip->fb_h);
  printf("Framebuffer: width=%d, height=%d\n", chip->fb_w, chip->fb_h);
  chip->plot_h = chip->fb_h - chip->serial_h;

  chip->sample_us = attr_read(chip->sampletime_attr);
  chip->capture_ms = ((chip->fb_w - 2) * chip->sample_us) / 1000;

  fill_string(chip);
  fill_plot(chip);

  const timer_config_t timer_config = {
    .callback = chip_timer_event,
    .user_data = chip,
  };

  chip->timer = timer_init(&timer_config);
  timer_start(chip->timer, 100, true);
}

void chip_timer_event(void *user_data) {
  chip_state_t *chip = (chip_state_t*)user_data;
  chip->sample_ad0 = pin_adc_read(chip->pin_AD0);
  if (chip->sample_ad0 < chip->sample_min0) chip->sample_min0 = chip->sample_ad0;
  if (chip->sample_ad0 > chip->sample_max0) chip->sample_max0 = chip->sample_ad0;
  chip->sample_ad1 = pin_adc_read(chip->pin_AD1);
  if (chip->sample_ad1 < chip->sample_min1) chip->sample_min1 = chip->sample_ad1;
  if (chip->sample_ad1 > chip->sample_max1) chip->sample_max1 = chip->sample_ad1;
  chip->sample_ad2 = pin_adc_read(chip->pin_AD2);
  if (chip->sample_ad2 < chip->sample_min2) chip->sample_min2 = chip->sample_ad2;
  if (chip->sample_ad2 > chip->sample_max2) chip->sample_max2 = chip->sample_ad2;

/*
  float decay = chip->sample_us * 0.000001;  // slow analog decay
  chip->sample_min0 += decay ;
  chip->sample_min1 += decay;
  chip->sample_min2 += decay;
  chip->sample_max0 -= decay;
  chip->sample_max1 -= decay;
  chip->sample_max2 -= decay;
  */

  if (attr_read(chip->trigger_attr) == 2) { // falling
    if (chip->plot_x < chip->fb_w - 1) draw_plot(chip);
    if ((chip->plot_x == chip->fb_w - 1) && (chip->sample_ad0 < chip->sample_last_ad0)) draw_plot(chip);
  }
  else if (attr_read(chip->trigger_attr) == 1) { // rising
    if (chip->plot_x < chip->fb_w - 1) draw_plot(chip);
    if ((chip->plot_x == chip->fb_w - 1) && (chip->sample_ad0 > chip->sample_last_ad0)) draw_plot(chip);
  }
  else  draw_plot(chip); // auto trigger = 0 (off)
  chip->sample_last_ad0 = chip->sample_ad0;

  if (chip->sample_us != attr_read(chip->sampletime_attr)) {
    chip->sample_us = attr_read(chip->sampletime_attr);
    chip->capture_ms = ((chip->fb_w - 2) * chip->sample_us) / 1000;
    timer_start(chip->timer, chip->sample_us, true);
  }
  if (chip->timer_count == 0) draw_string(chip);
  chip->timer_count++;
}

void draw_string(chip_state_t *chip) {
  char serial_a[32];
  char serial_b[32];
  char serial_c[32];
  snprintf (serial_a, 32, "%1.1f Vmin %1.1f Vmax %4d us", chip->sample_min0, chip->sample_max0, chip->sample_us);
  snprintf (serial_b, 32, "%1.1f Vmin %1.1f Vmax %4d ms", chip->sample_min1, chip->sample_max1, chip->capture_ms);
  snprintf (serial_c, 32, "%1.1f Vmin %1.1f Vmax       ", chip->sample_min2, chip->sample_max2);
  rgba_t color;
  int ascii, yy;
  chip->serial_y = chip->fb_h - chip->serial_h + 2;
  for (int c = 0; c < 78; c++) {
    chip->serial_x = (c % 26) * 9;
    ascii = (c < 26) ? serial_a[c % 26] : (c < 52) ? serial_b[c % 26] : serial_c[c % 26];
    yy =  (c < 26) ? 1 : (c < 52) ? 12 : 23;
    char *bitmap = font8x8[ascii];
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        color = (bitmap[y] & (1 << x)) ? chip->white : chip->green;
        buffer_write(chip->framebuffer, (chip->fb_w * 4 * (y + yy + chip->serial_y)) + ((x + 10 + chip->serial_x) * 4), &color, sizeof(color));
      }
    }
  }
}

void draw_plot(chip_state_t *chip) {
  rgba_t color;

  chip->plot_y0 = 24 - chip->sample_ad0 / 5.0 * 20;
  for (int y = 4; y < 26; y += 1) {
   color = ((chip->plot_y0 >= 4 && chip->plot_y0 <= 26) &&
             (y < chip->plot_y0 && y < chip->plot_py0) ||
             (y > chip->plot_y0 && y > chip->plot_py0) ||
             (chip->plot_x == chip->fb_w - 1) ||
             (chip->plot_x == 0)) ? chip->background : chip->green;
    buffer_write(chip->framebuffer, (chip->fb_w * 4 * y) + (chip->plot_x * 4), &color, sizeof(color));
  }

  chip->plot_y1 = 50 - chip->sample_ad1 / 5.0 * 20;
  for (int y = 30; y < 52; y += 1) {
   color = ((chip->plot_y1 >= 30 && chip->plot_y1 <= 52) &&
             (y < chip->plot_y1 && y < chip->plot_py1) ||
             (y > chip->plot_y1 && y > chip->plot_py1) ||
             (chip->plot_x == chip->fb_w - 1) ||
             (chip->plot_x == 0)) ? chip->background : chip->green;
    buffer_write(chip->framebuffer, (chip->fb_w * 4 * y) + (chip->plot_x * 4), &color, sizeof(color));
  }

  chip->plot_y2 = 76 - chip->sample_ad2 / 5.0 * 20;
  for (int y = 56; y < 78; y += 1) {
   color = ((chip->plot_y2 >= 56 && chip->plot_y2 <= 78) &&
             (y < chip->plot_y2 && y < chip->plot_py2) ||
             (y > chip->plot_y2 && y > chip->plot_py2) ||
             (chip->plot_x == chip->fb_w - 1) ||
             (chip->plot_x == 0)) ? chip->background : chip->green;
    buffer_write(chip->framebuffer, (chip->fb_w * 4 * y) + (chip->plot_x * 4), &color, sizeof(color));
  }

  chip->plot_py0 = chip->plot_y0;
  chip->plot_py1 = chip->plot_y1;
  chip->plot_py2 = chip->plot_y2;
  chip->plot_x = (chip->plot_x + 1) % chip->fb_w;
}

void fill_string(chip_state_t *chip) {
  for (int x = 0; x < chip->fb_w; x += 1) {
    for (int y = chip->fb_h - chip->serial_h; y < chip->fb_h; y += 1) {
      buffer_write(chip->framebuffer, (chip->fb_w * 4 * y) + (x * 4), &chip->green, sizeof(chip->green));
    }
  }
}

void fill_plot(chip_state_t *chip) {
  for (int x = 0; x < chip->fb_w; x += 1) {
    for (int y = 0; y < chip->fb_h - chip->serial_h; y += 1) {
      buffer_write(chip->framebuffer, (chip->fb_w * 4 * y) + (x * 4), &chip->background, sizeof(chip->background));
    }
  }
}
