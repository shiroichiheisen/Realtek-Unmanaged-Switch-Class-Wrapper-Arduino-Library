#ifndef _rtl_mirror_hpp_
#define _rtl_mirror_hpp_

#include <Arduino.h>

extern "C"
{
#include "mirror.h"
#include "rtk_types.h"
}

class rtl_mirror
{
public:
    /* Function Name:
     *      rtl_mirror_portBased_set
     * Description:
     *      Set port mirror function.
     * Input:
     *      mirroring_port          - Monitor port.
     *      pMirrored_rx_portmask   - Rx mirror port mask.
     *      pMirrored_tx_portmask   - Tx mirror port mask.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number
     *      RT_ERR_PORT_MASK    - Invalid portmask.
     * Note:
     *      The API is to set mirror function of source port and mirror port.
     *      The mirror port can only be set to one port and the TX and RX mirror ports
     *      should be identical.
     */
    rtk_api_ret_t rtl_mirror_portBased_set(rtk_port_t mirroring_port, rtk_portmask_t *pMirrored_rx_portmask, rtk_portmask_t *pMirrored_tx_portmask)
    {
        return rtk_mirror_portBased_set(mirroring_port, pMirrored_rx_portmask, pMirrored_tx_portmask);
    }

    /* Function Name:
     *      rtl_mirror_portBased_get
     * Description:
     *      Get port mirror function.
     * Input:
     *      None
     * Output:
     *      pMirroring_port         - Monitor port.
     *      pMirrored_rx_portmask   - Rx mirror port mask.
     *      pMirrored_tx_portmask   - Tx mirror port mask.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API is to get mirror function of source port and mirror port.
     */
    rtk_api_ret_t rtl_mirror_portBased_get(rtk_port_t *pMirroring_port, rtk_portmask_t *pMirrored_rx_portmask, rtk_portmask_t *pMirrored_tx_portmask)
    {
        return rtk_mirror_portBased_get(pMirroring_port, pMirrored_rx_portmask, pMirrored_tx_portmask);
    }

    /* Function Name:
     *      rtl_mirror_portIso_set
     * Description:
     *      Set mirror port isolation.
     * Input:
     *      enable |Mirror isolation status.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_ENABLE       - Invalid enable input
     * Note:
     *      The API is to set mirror isolation function that prevent normal forwarding packets to miror port.
     */
    rtk_api_ret_t rtl_mirror_portIso_set(rtk_enable_t enable)
    {
        return rtk_mirror_portIso_set(enable);
    }

    /* Function Name:
     *      rtl_mirror_portIso_get
     * Description:
     *      Get mirror port isolation.
     * Input:
     *      None
     * Output:
     *      pEnable |Mirror isolation status.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API is to get mirror isolation status.
     */
    rtk_api_ret_t rtl_mirror_portIso_get(rtk_enable_t *pEnable)
    {
        return rtk_mirror_portIso_get(pEnable);
    }

    /* Function Name:
     *      rtl_mirror_vlanLeaky_set
     * Description:
     *      Set mirror VLAN leaky.
     * Input:
     *      txenable -TX leaky enable.
     *      rxenable - RX leaky enable.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_ENABLE       - Invalid enable input
     * Note:
     *      The API is to set mirror VLAN leaky function forwarding packets to miror port.
     */
    rtk_api_ret_t rtl_mirror_vlanLeaky_set(rtk_enable_t txenable, rtk_enable_t rxenable)
    {
        return rtk_mirror_vlanLeaky_set(txenable, rxenable);
    }

    /* Function Name:
     *      rtl_mirror_vlanLeaky_get
     * Description:
     *      Get mirror VLAN leaky.
     * Input:
     *      None
     * Output:
     *      pTxenable - TX leaky enable.
     *      pRxenable - RX leaky enable.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API is to get mirror VLAN leaky status.
     */
    rtk_api_ret_t rtl_mirror_vlanLeaky_get(rtk_enable_t *pTxenable, rtk_enable_t *pRxenable)
    {
        return rtk_mirror_vlanLeaky_get(pTxenable, pRxenable);
    }

    /* Function Name:
     *      rtl_mirror_isolationLeaky_set
     * Description:
     *      Set mirror Isolation leaky.
     * Input:
     *      txenable -TX leaky enable.
     *      rxenable - RX leaky enable.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_ENABLE       - Invalid enable input
     * Note:
     *      The API is to set mirror VLAN leaky function forwarding packets to miror port.
     */
    rtk_api_ret_t rtl_mirror_isolationLeaky_set(rtk_enable_t txenable, rtk_enable_t rxenable)
    {
        return rtk_mirror_isolationLeaky_set(txenable, rxenable);
    }

    /* Function Name:
     *      rtl_mirror_isolationLeaky_get
     * Description:
     *      Get mirror isolation leaky.
     * Input:
     *      None
     * Output:
     *      pTxenable - TX leaky enable.
     *      pRxenable - RX leaky enable.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API is to get mirror isolation leaky status.
     */
    rtk_api_ret_t rtl_mirror_isolationLeaky_get(rtk_enable_t *pTxenable, rtk_enable_t *pRxenable)
    {
        return rtk_mirror_isolationLeaky_get(pTxenable, pRxenable);
    }

    /* Function Name:
     *      rtl_mirror_keep_set
     * Description:
     *      Set mirror packet format keep.
     * Input:
     *      mode - -mirror keep mode.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_ENABLE       - Invalid enable input
     * Note:
     *      The API is to set  -mirror keep mode.
     *      The mirror keep mode is as following:
     *      - MIRROR_FOLLOW_VLAN
     *      - MIRROR_KEEP_ORIGINAL
     *      - MIRROR_KEEP_END
     */
    rtk_api_ret_t rtl_mirror_keep_set(rtk_mirror_keep_t mode)
    {
        return rtk_mirror_keep_set(mode);
    }

    /* Function Name:
     *      rtl_mirror_keep_get
     * Description:
     *      Get mirror packet format keep.
     * Input:
     *      None
     * Output:
     *      pMode -mirror keep mode.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API is to get mirror keep mode.
     *      The mirror keep mode is as following:
     *      - MIRROR_FOLLOW_VLAN
     *      - MIRROR_KEEP_ORIGINAL
     *      - MIRROR_KEEP_END
     */
    rtk_api_ret_t rtl_mirror_keep_get(rtk_mirror_keep_t *pMode)
    {
        return rtk_mirror_keep_get(pMode);
    }

    /* Function Name:
     *      rtl_mirror_override_set
     * Description:
     *      Set port mirror override function.
     * Input:
     *      rxMirror        - 1: output mirrored packet, 0: output normal forward packet
     *      txMirror        - 1: output mirrored packet, 0: output normal forward packet
     *      aclMirror       - 1: output mirrored packet, 0: output normal forward packet
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      The API is to set mirror override function.
     *      This function control the output format when a port output
     *      normal forward & mirrored packet at the same time.
     */
    rtk_api_ret_t rtl_mirror_override_set(rtk_enable_t rxMirror, rtk_enable_t txMirror, rtk_enable_t aclMirror)
    {
        return rtk_mirror_override_set(rxMirror, txMirror, aclMirror);
    }

    /* Function Name:
     *      rtl_mirror_override_get
     * Description:
     *      Get port mirror override function.
     * Input:
     *      None
     * Output:
     *      pRxMirror       - 1: output mirrored packet, 0: output normal forward packet
     *      pTxMirror       - 1: output mirrored packet, 0: output normal forward packet
     *      pAclMirror      - 1: output mirrored packet, 0: output normal forward packet
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_NULL_POINTER - Null Pointer
     * Note:
     *      The API is to Get mirror override function.
     *      This function control the output format when a port output
     *      normal forward & mirrored packet at the same time.
     */
    rtk_api_ret_t rtl_mirror_override_get(rtk_enable_t *pRxMirror, rtk_enable_t *pTxMirror, rtk_enable_t *pAclMirror)
    {
        return rtk_mirror_override_get(pRxMirror, pTxMirror, pAclMirror);
    }
};

#endif