#ifndef _rtl_rldp_hpp_
#define _rtl_rldp_hpp_

#include <Arduino.h>

extern "C"
{
#include "rldp.h"
#include "rtk_types.h"
}

class rtl_rldp
{
public:
    /* Function Name:
     *      rtl_rldp_config_set
     * Description:
     *      Set RLDP module configuration
     * Input:
     *      pConfig - configuration structure of RLDP
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_INPUT
     *      RT_ERR_NULL_POINTER
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_rldp_config_set(rtk_rldp_config_t *pConfig)
    {
        return rtk_rldp_config_set(pConfig);
    }

    /* Function Name:
     *      rtl_rldp_config_get
     * Description:
     *      Get RLDP module configuration
     * Input:
     *      None
     * Output:
     *      pConfig - configuration structure of RLDP
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_INPUT
     *      RT_ERR_NULL_POINTER
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_rldp_config_get(rtk_rldp_config_t *pConfig)
    {
        return rtk_rldp_config_get(pConfig);
    }

    /* Function Name:
     *      rtl_rldp_portConfig_set
     * Description:
     *      Set per port RLDP module configuration
     * Input:
     *      port   - port number to be configured
     *      pPortConfig - per port configuration structure of RLDP
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_INPUT
     *      RT_ERR_NULL_POINTER
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_rldp_portConfig_set(rtk_port_t port, rtk_rldp_portConfig_t *pPortConfig)
    {
        return rtk_rldp_portConfig_set(port, pPortConfig);
    }

    /* Function Name:
     *      rtl_rldp_portConfig_get
     * Description:
     *      Get per port RLDP module configuration
     * Input:
     *      port    - port number to be get
     * Output:
     *      pPortConfig - per port configuration structure of RLDP
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_INPUT
     *      RT_ERR_NULL_POINTER
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_rldp_portConfig_get(rtk_port_t port, rtk_rldp_portConfig_t *pPortConfig)
    {
        return rtk_rldp_portConfig_get(port, pPortConfig);
    }

    /* Function Name:
     *      rtl_rldp_status_get
     * Description:
     *      Get RLDP module status
     * Input:
     *      None
     * Output:
     *      pStatus - status structure of RLDP
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_NULL_POINTER
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_rldp_status_get(rtk_rldp_status_t *pStatus)
    {
        return rtk_rldp_status_get(pStatus);
    }

    /* Function Name:
     *      rtl_rldp_portStatus_get
     * Description:
     *      Get RLDP module status
     * Input:
     *      port    - port number to be get
     * Output:
     *      pPortStatus - per port status structure of RLDP
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_INPUT
     *      RT_ERR_NULL_POINTER
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_rldp_portStatus_get(rtk_port_t port, rtk_rldp_portStatus_t *pPortStatus)
    {
        return rtk_rldp_portStatus_get(port, pPortStatus);
    }

    /* Function Name:
     *      rtl_rldp_portStatus_set
     * Description:
     *      Clear RLDP module status
     * Input:
     *      port    - port number to be clear
     *      pPortStatus - per port status structure of RLDP
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_INPUT
     *      RT_ERR_NULL_POINTER
     * Note:
     *      Clear operation effect loop_enter and loop_leave only, other field in
     *      the structure are don't care
     */
    rtk_api_ret_t rtl_rldp_portStatus_set(rtk_port_t port, rtk_rldp_portStatus_t *pPortStatus)
    {
        return rtk_rldp_portStatus_set(port, pPortStatus);
    }

    /* Function Name:
     *      rtl_rldp_portLoopPair_get
     * Description:
     *      Get RLDP port loop pairs
     * Input:
     *      port    - port number to be get
     * Output:
     *      pPortmask - per port related loop ports
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_INPUT
     *      RT_ERR_NULL_POINTER
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_rldp_portLoopPair_get(rtk_port_t port, rtk_portmask_t *pPortmask)
    {
        return rtk_rldp_portLoopPair_get(port, pPortmask);
    }
};

#endif