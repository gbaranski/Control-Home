#ifndef CONFIG_H
#pragma once

#include <Arduino.h>
#include <string.h>

#define RELAY_PIN 4

size_t letsencryptauthorityx3_der_len = 1425;
const uint8_t letsencryptauthorityx3_der[] = {
    0x30, 0x82, 0x05, 0x8d, 0x30, 0x82, 0x03, 0x75, 0xa0, 0x03, 0x02, 0x01,
    0x02, 0x02, 0x11, 0x00, 0xd3, 0xb1, 0x72, 0x26, 0x34, 0x23, 0x32, 0xdc,
    0xf4, 0x05, 0x28, 0x51, 0x2a, 0xec, 0x9c, 0x6a, 0x30, 0x0d, 0x06, 0x09,
    0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x30,
    0x4f, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
    0x55, 0x53, 0x31, 0x29, 0x30, 0x27, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x13,
    0x20, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x6e, 0x65, 0x74, 0x20, 0x53, 0x65,
    0x63, 0x75, 0x72, 0x69, 0x74, 0x79, 0x20, 0x52, 0x65, 0x73, 0x65, 0x61,
    0x72, 0x63, 0x68, 0x20, 0x47, 0x72, 0x6f, 0x75, 0x70, 0x31, 0x15, 0x30,
    0x13, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x0c, 0x49, 0x53, 0x52, 0x47,
    0x20, 0x52, 0x6f, 0x6f, 0x74, 0x20, 0x58, 0x31, 0x30, 0x1e, 0x17, 0x0d,
    0x31, 0x36, 0x31, 0x30, 0x30, 0x36, 0x31, 0x35, 0x34, 0x33, 0x35, 0x35,
    0x5a, 0x17, 0x0d, 0x32, 0x31, 0x31, 0x30, 0x30, 0x36, 0x31, 0x35, 0x34,
    0x33, 0x35, 0x35, 0x5a, 0x30, 0x4a, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03,
    0x55, 0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x16, 0x30, 0x14, 0x06,
    0x03, 0x55, 0x04, 0x0a, 0x13, 0x0d, 0x4c, 0x65, 0x74, 0x27, 0x73, 0x20,
    0x45, 0x6e, 0x63, 0x72, 0x79, 0x70, 0x74, 0x31, 0x23, 0x30, 0x21, 0x06,
    0x03, 0x55, 0x04, 0x03, 0x13, 0x1a, 0x4c, 0x65, 0x74, 0x27, 0x73, 0x20,
    0x45, 0x6e, 0x63, 0x72, 0x79, 0x70, 0x74, 0x20, 0x41, 0x75, 0x74, 0x68,
    0x6f, 0x72, 0x69, 0x74, 0x79, 0x20, 0x58, 0x33, 0x30, 0x82, 0x01, 0x22,
    0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
    0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01, 0x0a,
    0x02, 0x82, 0x01, 0x01, 0x00, 0x9c, 0xd3, 0x0c, 0xf0, 0x5a, 0xe5, 0x2e,
    0x47, 0xb7, 0x72, 0x5d, 0x37, 0x83, 0xb3, 0x68, 0x63, 0x30, 0xea, 0xd7,
    0x35, 0x26, 0x19, 0x25, 0xe1, 0xbd, 0xbe, 0x35, 0xf1, 0x70, 0x92, 0x2f,
    0xb7, 0xb8, 0x4b, 0x41, 0x05, 0xab, 0xa9, 0x9e, 0x35, 0x08, 0x58, 0xec,
    0xb1, 0x2a, 0xc4, 0x68, 0x87, 0x0b, 0xa3, 0xe3, 0x75, 0xe4, 0xe6, 0xf3,
    0xa7, 0x62, 0x71, 0xba, 0x79, 0x81, 0x60, 0x1f, 0xd7, 0x91, 0x9a, 0x9f,
    0xf3, 0xd0, 0x78, 0x67, 0x71, 0xc8, 0x69, 0x0e, 0x95, 0x91, 0xcf, 0xfe,
    0xe6, 0x99, 0xe9, 0x60, 0x3c, 0x48, 0xcc, 0x7e, 0xca, 0x4d, 0x77, 0x12,
    0x24, 0x9d, 0x47, 0x1b, 0x5a, 0xeb, 0xb9, 0xec, 0x1e, 0x37, 0x00, 0x1c,
    0x9c, 0xac, 0x7b, 0xa7, 0x05, 0xea, 0xce, 0x4a, 0xeb, 0xbd, 0x41, 0xe5,
    0x36, 0x98, 0xb9, 0xcb, 0xfd, 0x6d, 0x3c, 0x96, 0x68, 0xdf, 0x23, 0x2a,
    0x42, 0x90, 0x0c, 0x86, 0x74, 0x67, 0xc8, 0x7f, 0xa5, 0x9a, 0xb8, 0x52,
    0x61, 0x14, 0x13, 0x3f, 0x65, 0xe9, 0x82, 0x87, 0xcb, 0xdb, 0xfa, 0x0e,
    0x56, 0xf6, 0x86, 0x89, 0xf3, 0x85, 0x3f, 0x97, 0x86, 0xaf, 0xb0, 0xdc,
    0x1a, 0xef, 0x6b, 0x0d, 0x95, 0x16, 0x7d, 0xc4, 0x2b, 0xa0, 0x65, 0xb2,
    0x99, 0x04, 0x36, 0x75, 0x80, 0x6b, 0xac, 0x4a, 0xf3, 0x1b, 0x90, 0x49,
    0x78, 0x2f, 0xa2, 0x96, 0x4f, 0x2a, 0x20, 0x25, 0x29, 0x04, 0xc6, 0x74,
    0xc0, 0xd0, 0x31, 0xcd, 0x8f, 0x31, 0x38, 0x95, 0x16, 0xba, 0xa8, 0x33,
    0xb8, 0x43, 0xf1, 0xb1, 0x1f, 0xc3, 0x30, 0x7f, 0xa2, 0x79, 0x31, 0x13,
    0x3d, 0x2d, 0x36, 0xf8, 0xe3, 0xfc, 0xf2, 0x33, 0x6a, 0xb9, 0x39, 0x31,
    0xc5, 0xaf, 0xc4, 0x8d, 0x0d, 0x1d, 0x64, 0x16, 0x33, 0xaa, 0xfa, 0x84,
    0x29, 0xb6, 0xd4, 0x0b, 0xc0, 0xd8, 0x7d, 0xc3, 0x93, 0x02, 0x03, 0x01,
    0x00, 0x01, 0xa3, 0x82, 0x01, 0x67, 0x30, 0x82, 0x01, 0x63, 0x30, 0x0e,
    0x06, 0x03, 0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff, 0x04, 0x04, 0x03, 0x02,
    0x01, 0x86, 0x30, 0x12, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff,
    0x04, 0x08, 0x30, 0x06, 0x01, 0x01, 0xff, 0x02, 0x01, 0x00, 0x30, 0x54,
    0x06, 0x03, 0x55, 0x1d, 0x20, 0x04, 0x4d, 0x30, 0x4b, 0x30, 0x08, 0x06,
    0x06, 0x67, 0x81, 0x0c, 0x01, 0x02, 0x01, 0x30, 0x3f, 0x06, 0x0b, 0x2b,
    0x06, 0x01, 0x04, 0x01, 0x82, 0xdf, 0x13, 0x01, 0x01, 0x01, 0x30, 0x30,
    0x30, 0x2e, 0x06, 0x08, 0x2b, 0x06, 0x01, 0x05, 0x05, 0x07, 0x02, 0x01,
    0x16, 0x22, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x63, 0x70, 0x73,
    0x2e, 0x72, 0x6f, 0x6f, 0x74, 0x2d, 0x78, 0x31, 0x2e, 0x6c, 0x65, 0x74,
    0x73, 0x65, 0x6e, 0x63, 0x72, 0x79, 0x70, 0x74, 0x2e, 0x6f, 0x72, 0x67,
    0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0xa8,
    0x4a, 0x6a, 0x63, 0x04, 0x7d, 0xdd, 0xba, 0xe6, 0xd1, 0x39, 0xb7, 0xa6,
    0x45, 0x65, 0xef, 0xf3, 0xa8, 0xec, 0xa1, 0x30, 0x33, 0x06, 0x03, 0x55,
    0x1d, 0x1f, 0x04, 0x2c, 0x30, 0x2a, 0x30, 0x28, 0xa0, 0x26, 0xa0, 0x24,
    0x86, 0x22, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x63, 0x72, 0x6c,
    0x2e, 0x72, 0x6f, 0x6f, 0x74, 0x2d, 0x78, 0x31, 0x2e, 0x6c, 0x65, 0x74,
    0x73, 0x65, 0x6e, 0x63, 0x72, 0x79, 0x70, 0x74, 0x2e, 0x6f, 0x72, 0x67,
    0x30, 0x72, 0x06, 0x08, 0x2b, 0x06, 0x01, 0x05, 0x05, 0x07, 0x01, 0x01,
    0x04, 0x66, 0x30, 0x64, 0x30, 0x30, 0x06, 0x08, 0x2b, 0x06, 0x01, 0x05,
    0x05, 0x07, 0x30, 0x01, 0x86, 0x24, 0x68, 0x74, 0x74, 0x70, 0x3a, 0x2f,
    0x2f, 0x6f, 0x63, 0x73, 0x70, 0x2e, 0x72, 0x6f, 0x6f, 0x74, 0x2d, 0x78,
    0x31, 0x2e, 0x6c, 0x65, 0x74, 0x73, 0x65, 0x6e, 0x63, 0x72, 0x79, 0x70,
    0x74, 0x2e, 0x6f, 0x72, 0x67, 0x2f, 0x30, 0x30, 0x06, 0x08, 0x2b, 0x06,
    0x01, 0x05, 0x05, 0x07, 0x30, 0x02, 0x86, 0x24, 0x68, 0x74, 0x74, 0x70,
    0x3a, 0x2f, 0x2f, 0x63, 0x65, 0x72, 0x74, 0x2e, 0x72, 0x6f, 0x6f, 0x74,
    0x2d, 0x78, 0x31, 0x2e, 0x6c, 0x65, 0x74, 0x73, 0x65, 0x6e, 0x63, 0x72,
    0x79, 0x70, 0x74, 0x2e, 0x6f, 0x72, 0x67, 0x2f, 0x30, 0x1f, 0x06, 0x03,
    0x55, 0x1d, 0x23, 0x04, 0x18, 0x30, 0x16, 0x80, 0x14, 0x79, 0xb4, 0x59,
    0xe6, 0x7b, 0xb6, 0xe5, 0xe4, 0x01, 0x73, 0x80, 0x08, 0x88, 0xc8, 0x1a,
    0x58, 0xf6, 0xe9, 0x9b, 0x6e, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48,
    0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x03, 0x82, 0x02, 0x01,
    0x00, 0x19, 0xcf, 0x75, 0x20, 0x34, 0x2d, 0x3a, 0xa6, 0x45, 0xff, 0xd0,
    0xd5, 0xe6, 0x8c, 0xda, 0x32, 0xe8, 0x9c, 0x6e, 0x1b, 0x41, 0xd1, 0x27,
    0xa8, 0xe2, 0x50, 0xf2, 0x70, 0xaa, 0xc4, 0xe7, 0x93, 0x46, 0xb4, 0xe8,
    0x10, 0xab, 0x70, 0x4f, 0xef, 0xb7, 0xea, 0x04, 0xd2, 0x94, 0x11, 0xb1,
    0x03, 0xfe, 0x5d, 0xba, 0xdf, 0x36, 0x8c, 0x94, 0x36, 0x8f, 0x13, 0x7c,
    0x44, 0x8f, 0x0b, 0xf5, 0x01, 0x57, 0xad, 0x68, 0xb8, 0xc5, 0x79, 0xc0,
    0xd8, 0x4a, 0x80, 0xd7, 0x4c, 0xa3, 0x1e, 0x24, 0x7a, 0x1f, 0xd7, 0x23,
    0xe8, 0xc1, 0x62, 0x3a, 0x76, 0xf9, 0x22, 0x7d, 0x5e, 0x5a, 0xc4, 0x4c,
    0x50, 0xcd, 0xaf, 0xdd, 0xef, 0x6d, 0x36, 0xc0, 0x80, 0x80, 0x1b, 0xa4,
    0x3c, 0x70, 0x20, 0xd6, 0x54, 0x21, 0xd3, 0xba, 0xef, 0x14, 0xa9, 0xbf,
    0x07, 0x3f, 0x41, 0x0a, 0x36, 0xb1, 0xa2, 0xb0, 0x0b, 0x20, 0xd5, 0x1f,
    0x67, 0xd0, 0xc3, 0xeb, 0x88, 0xf6, 0x8a, 0x02, 0xc8, 0xc6, 0x57, 0xb6,
    0x0c, 0xfc, 0x56, 0xf1, 0xd2, 0x3f, 0x17, 0x69, 0x68, 0x1c, 0xc8, 0xd7,
    0x66, 0x3a, 0x86, 0xf1, 0x19, 0x2a, 0x65, 0x47, 0x68, 0xc6, 0xd2, 0x03,
    0xe7, 0xef, 0x74, 0x16, 0x0b, 0x06, 0x21, 0xf9, 0x0c, 0xa6, 0xa8, 0x11,
    0x4b, 0x4e, 0x5f, 0xe3, 0x33, 0xdb, 0x08, 0x41, 0xea, 0x09, 0x79, 0x75,
    0x78, 0xee, 0x47, 0xc8, 0x42, 0xd3, 0x81, 0xc5, 0x65, 0x2d, 0x75, 0xd0,
    0x0e, 0x00, 0x16, 0x9d, 0x1c, 0xee, 0xb7, 0x58, 0x45, 0x25, 0xe7, 0x33,
    0x63, 0x5b, 0x63, 0x41, 0x09, 0xe8, 0xe9, 0xfe, 0xac, 0xfa, 0x73, 0x32,
    0x74, 0xb3, 0x76, 0xe9, 0x6b, 0x94, 0xe2, 0xcd, 0xd4, 0x62, 0xf3, 0xae,
    0x3a, 0xc5, 0x31, 0x46, 0x52, 0x6e, 0xed, 0x34, 0x91, 0x1e, 0xa0, 0xc2,
    0xde, 0x54, 0x84, 0xe5, 0x78, 0x20, 0x56, 0x4c, 0xdd, 0x68, 0xf9, 0x2e,
    0x28, 0x64, 0x1b, 0x1a, 0x99, 0xf2, 0xfb, 0x4d, 0x7f, 0xe3, 0xb8, 0x5f,
    0x5d, 0x73, 0x41, 0xec, 0x79, 0xed, 0x58, 0xd6, 0x7a, 0x37, 0x65, 0x70,
    0xa7, 0xb1, 0xba, 0x39, 0xf6, 0x3e, 0x61, 0x0a, 0xd9, 0xc0, 0x86, 0x90,
    0x9a, 0x1a, 0xc8, 0xa8, 0x96, 0x6e, 0x8a, 0x0b, 0x2b, 0x6d, 0xed, 0xd6,
    0xfa, 0x07, 0x67, 0xe7, 0x29, 0x04, 0xf7, 0xe2, 0xb2, 0xd1, 0x58, 0x15,
    0x52, 0xc7, 0xf1, 0xa3, 0x9d, 0xa6, 0xc0, 0x56, 0x2c, 0xd4, 0x92, 0x98,
    0xd8, 0xf1, 0x83, 0xb9, 0x6c, 0x7c, 0x33, 0xa0, 0xe5, 0x4b, 0xaa, 0x90,
    0x92, 0xf1, 0xda, 0x45, 0x4a, 0x34, 0x14, 0xc7, 0x7c, 0x4e, 0xc4, 0xa5,
    0x6c, 0x5d, 0x3f, 0xbf, 0xde, 0xb9, 0xa8, 0x61, 0x4a, 0x85, 0x20, 0xde,
    0x42, 0x83, 0x29, 0x62, 0x7c, 0x1c, 0x99, 0x08, 0xa5, 0x46, 0x1f, 0xf4,
    0x6b, 0x22, 0xd3, 0x86, 0x51, 0xcb, 0x37, 0xcd, 0x60, 0x4a, 0x42, 0x63,
    0x56, 0xb3, 0xc8, 0xd1, 0x8f, 0x31, 0x09, 0x53, 0xc1, 0xe2, 0xdc, 0x1b,
    0xd4, 0xf1, 0x54, 0x77, 0x67, 0xcf, 0x33, 0x7b, 0x00, 0xd6, 0xd2, 0x7c,
    0xde, 0xc6, 0x79, 0xbf, 0xcb, 0xe0, 0x16, 0xfd, 0xb2, 0xa1, 0xf2, 0x91,
    0x3c, 0x1d, 0x2d, 0xe8, 0x9c, 0xd4, 0x03, 0xcd, 0x66, 0x4a, 0xa3, 0x37,
    0x93, 0x19, 0x79, 0x7b, 0xe2, 0x19, 0xc2, 0x16, 0x00, 0xc8, 0xed, 0x0e,
    0x4e, 0x0d, 0xff, 0x7e, 0xcf, 0x07, 0xa8, 0x64, 0xcd, 0x29, 0xdf, 0x41,
    0xaa, 0x85, 0x30, 0x49, 0x10, 0x73, 0xa7, 0x4e, 0x89, 0x32, 0x0e, 0x5b,
    0xad, 0x40, 0x86, 0xc1, 0xb0, 0x94, 0x0c, 0x8d, 0x26, 0xc5, 0xa7, 0x49,
    0xdc, 0x1c, 0xf8, 0x5b, 0x14, 0x7a, 0x7f, 0x23, 0x69, 0x04, 0xad, 0xb2,
    0x02, 0x29, 0xd6, 0x12, 0xc8, 0xa4, 0xc6, 0xa1, 0x2d};

#endif
