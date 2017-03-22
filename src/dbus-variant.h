#pragma once

/*
 * D-Bus Variants
 */

#include <c-macro.h>
#include <stdlib.h>

typedef struct DBusVariantType DBusVariantType;

/*
 * DBUS_VARIANT_TYPE_?: Those macros are initializers for builtin types. They
 *                      can be used to initialize DBusVariantType objects, if
 *                      needed.
 *                      Note that these are given as tuples, so you might have
 *                      to strip the surrounding brackets (via C_IDENTITY or
 *                      similar).
 */
#define DBUS_VARIANT_TYPE_b (1, 0, 1)
#define DBUS_VARIANT_TYPE_y (4, 2, 1)
#define DBUS_VARIANT_TYPE_n (2, 1, 1)
#define DBUS_VARIANT_TYPE_q (2, 1, 1)
#define DBUS_VARIANT_TYPE_i (4, 2, 1)
#define DBUS_VARIANT_TYPE_u (4, 2, 1)
#define DBUS_VARIANT_TYPE_x (8, 3, 1)
#define DBUS_VARIANT_TYPE_t (8, 3, 1)
#define DBUS_VARIANT_TYPE_h (4, 2, 1)
#define DBUS_VARIANT_TYPE_d (8, 3, 1)
#define DBUS_VARIANT_TYPE_s (0, 2, 1)
#define DBUS_VARIANT_TYPE_o (0, 2, 1)
#define DBUS_VARIANT_TYPE_g (0, 0, 1)
#define DBUS_VARIANT_TYPE_v (0, 0, 0)

/*
 * DBUS_VARIANT_TYPE_LENGTH_MAX: Maximum length of a DBus Type Signature, given
 *                               in number of characters (without terminating
 *                               0).
 * DBUS_VARIANT_TYPE_DEPTH_MAX: Maximum depth of a DBus Type Signature.
 * DBUS_VARIANT_TYPE_SIZE_BITS: Number of bits available to store the fixed
 *                              size of a DBus type.
 */
#define DBUS_VARIANT_TYPE_LENGTH_MAX (255)
#define DBUS_VARIANT_TYPE_DEPTH_MAX (64)
#define DBUS_VARIANT_TYPE_SIZE_BITS (11)

/*
 * struct DBusVariantType - Type Information
 * @size:               Size of this type, or 0 if not fixed-size. Note that
 *                      the size of a type is always a multiple of its
 *                      alignment.
 * @alignment:          Alignment of this type, given as a power of 2.
 * @basic:              Whether or not this is a basic type.
 * @valid:              Must be 1.
 */
struct DBusVariantType {
        uint16_t size : DBUS_VARIANT_TYPE_SIZE_BITS;
        uint16_t alignment : 3;
        uint16_t basic : 1;
        uint16_t valid : 1;
};

long dbus_variant_type_new_from_signature(DBusVariantType **infop,
                                          const char *signature,
                                          size_t n_signature);