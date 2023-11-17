#ifndef _rtl_eee_hpp_
#define _rtl_eee_hpp_

#include <Arduino.h>

extern "C"
{
#include "eee.h"
#include "rtk_types.h"
}

class rtl_eee
{
public:
    /* Function Name:
     *      rtl_eee_init
     * Description:
     *      EEE function initialization.
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      This API is used to initialize EEE status.
     */
    rtk_api_ret_t rtl_eee_init()
    {
        return rtk_eee_init();
    }

    /* Function Name:
     *      rtl_eee_portEnable_set
     * Description:
     *      Set enable status of EEE function.
     * Input:
     *      port - port id.
     *      enable - enable EEE status.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_PORT_ID - Invalid port number.
     *      RT_ERR_ENABLE - Invalid enable input.
     * Note:
     *      This API can set EEE function to the specific port.
     *      The configuration of the port is as following:
     *      - DISABLE
     *      - ENABLE
     */
    rtk_api_ret_t rtl_eee_portEnable_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_eee_portEnable_set(port, enable);
    }

    /* Function Name:
     *      rtl_eee_portEnable_get
     * Description:
     *      Get port admin configuration of the specific port.
     * Input:
     *      port - Port id.
     * Output:
     *      pEnable - Back pressure status.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_PORT_ID - Invalid port number.
     * Note:
     *      This API can set EEE function to the specific port.
     *      The configuration of the port is as following:
     *      - DISABLE
     *      - ENABLE
     */
    rtk_api_ret_t rtl_eee_portEnable_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_eee_portEnable_get(port, pEnable);
    }
};

#endif