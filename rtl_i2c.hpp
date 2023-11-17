#ifndef _rtl_i2c_hpp_
#define _rtl_i2c_hpp_

#include <Arduino.h>

extern "C"
{
#include "i2c.h"
#include "rtk_types.h"
}

class rtl_i2c
{
public:
    /* Function Name:
     *      rtl_i2c_data_read
     * Description:
     *      read i2c slave device register.
     * Input:
     *      deviceAddr   -   access Slave device address
     *      slaveRegAddr -   access Slave register address
     * Output:
     *      pRegData     -   read data
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_NULL_POINTER     - input parameter is null pointer
     * Note:
     *      The API can access i2c slave and read i2c slave device register.
     */
    rtk_api_ret_t rtl_i2c_data_read(rtk_uint8 deviceAddr, rtk_uint32 slaveRegAddr, rtk_uint32 *pRegData)
    {
        return rtk_i2c_data_read(deviceAddr, slaveRegAddr, pRegData);
    }

    /* Function Name:
     *      rtl_i2c_data_write
     * Description:
     *      write data to i2c slave device register
     * Input:
     *      deviceAddr   -   access Slave device address
     *      slaveRegAddr -   access Slave register address
     *      regData      -   data to set
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     * Note:
     *      The API can access i2c slave and setting i2c slave device register.
     */
    rtk_api_ret_t rtl_i2c_data_write(rtk_uint8 deviceAddr, rtk_uint32 slaveRegAddr, rtk_uint32 regData)
    {
        return rtk_i2c_data_write(deviceAddr, slaveRegAddr, regData);
    }

    /* Function Name:
     *      rtl_i2c_init
     * Description:
     *      I2C smart function initialization.
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     * Note:
     *      This API is used to initialize EEE status.
     *      need used GPIO pins
     *      OpenDrain and clock
     */
    rtk_api_ret_t rtl_i2c_init()
    {
        return rtk_i2c_init();
    }

    /* Function Name:
     *      rtl_i2c_mode_set
     * Description:
     *      Set I2C data byte-order.
     * Input:
     *      i2cmode - byte-order mode
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_INPUT        - Invalid input parameter.
     * Note:
     *      This API can set I2c traffic's byte-order .
     */
    rtk_api_ret_t rtl_i2c_mode_set(rtk_I2C_16bit_mode_t i2cmode)
    {
        return rtk_i2c_mode_set(i2cmode);
    }

    /* Function Name:
     *      rtl_i2c_mode_get
     * Description:
     *      Get i2c traffic byte-order setting.
     * Input:
     *      None
     * Output:
     *      pI2cMode - i2c byte-order
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_NULL_POINTER     - input parameter is null pointer
     * Note:
     *      The API can get i2c traffic byte-order setting.
     */
    rtk_api_ret_t rtl_i2c_mode_get(rtk_I2C_16bit_mode_t *pI2cMode)
    {
        return rtk_i2c_mode_get(pI2cMode);
    }

    /* Function Name:
     *      rtl_i2c_gpioPinGroup_set
     * Description:
     *      Set i2c SDA & SCL used GPIO pins group.
     * Input:
     *      pins_group - GPIO pins group
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_INPUT        - Invalid input parameter.
     * Note:
     *      The API can set i2c used gpio pins group.
     *      There are three group pins could be used
     */
    rtk_api_ret_t rtl_i2c_gpioPinGroup_set(rtk_I2C_gpio_pin_t pins_group)
    {
        return rtk_i2c_gpioPinGroup_set(pins_group);
    }

    /* Function Name:
     *      rtl_i2c_gpioPinGroup_get
     * Description:
     *      Get i2c SDA & SCL used GPIO pins group.
     * Input:
     *      None
     * Output:
     *      pPins_group - GPIO pins group
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_NULL_POINTER     - input parameter is null pointer
     * Note:
     *      The API can get i2c used gpio pins group.
     *      There are three group pins could be used
     */
    rtk_api_ret_t rtl_i2c_gpioPinGroup_get(rtk_I2C_gpio_pin_t *pPins_group)
    {
        return rtk_i2c_gpioPinGroup_get(pPins_group);
    }
};

#endif // _rtl_api_hpp_