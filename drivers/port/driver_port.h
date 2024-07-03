#ifndef DRIVERS_DRIVER_PORT_H_
#define DRIVERS_DRIVER_PORT_H_

/******************************************************************************
 * Includes
 ******************************************************************************/
#include "driver_common.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/
/* @brief Pin mux selection */
typedef enum _port_mux
{
    PORT_MuxAlt0             = 0U,
    PORT_MuxAlt1             = 1U,
    PORT_MuxAlt2             = 2U,
    PORT_MuxAlt3             = 3U,
    PORT_MuxAlt4             = 4U,
    PORT_MuxAlt5             = 5U,
    PORT_MuxAlt6             = 6U,
    PORT_MuxAlt7             = 7U,
} port_mux_t;

/******************************************************************************
 * API
 ******************************************************************************/
/**
 * @brief Configures the pin muxing.
 *
 * @param base  PORT peripheral base pointer.
 * @param pin   PORT pin number.
 * @param mux   pin muxing slot selection.
 */
static inline void PORT_DRV_SetPinMux(PORT_Type *base, uint32_t pin, port_mux_t mux)
{
    base->PCR[pin] = (base->PCR[pin] & ~PORT_PCR_MUX_MASK) | PORT_PCR_MUX(mux);
}

#endif /* DRIVERS_DRIVER_PORT_H_ */

/******************************************************************************
 * EOF
 ******************************************************************************/
