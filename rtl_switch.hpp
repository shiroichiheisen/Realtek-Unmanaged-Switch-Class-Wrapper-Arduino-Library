#ifndef _rtl_switch_hpp_
#define _rtl_switch_hpp_

#include <Arduino.h>

extern "C"
{
#include "rtk_switch.h"
#include "rtk_types.h"
}

class rtl_switch
{
public:
    /* Function Name:
     *      rtl_switch_probe
     * Description:
     *      Probe switch
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Switch probed
     *      RT_ERR_FAILED   - Switch Unprobed.
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_probe(switch_chip_t *pSwitchChip)
    {
        return rtk_switch_probe(pSwitchChip);
    }

    /* Function Name:
     *      rtl_switch_initialState_set
     * Description:
     *      Set initial status
     * Input:
     *      state   - Initial state;
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Initialized
     *      RT_ERR_FAILED   - Uninitialized
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_initialState_set(init_state_t state)
    {
        return rtk_switch_initialState_set(state);
    }

    /* Function Name:
     *      rtl_switch_initialState_get
     * Description:
     *      Get initial status
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      INIT_COMPLETED     - Initialized
     *      INIT_NOT_COMPLETED - Uninitialized
     * Note:
     *
     */
    init_state_t rtl_switch_initialState_get()
    {
        return rtk_switch_initialState_get();
    }

    /* Function Name:
     *      rtl_switch_logicalPortCheck
     * Description:
     *      Check logical port ID.
     * Input:
     *      logicalPort     - logical port ID
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Port ID is correct
     *      RT_ERR_FAILED   - Port ID is not correct
     *      RT_ERR_NOT_INIT - Not Initialize
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_logicalPortCheck(rtk_port_t logicalPort)
    {
        return rtk_switch_logicalPortCheck(logicalPort);
    }

    /* Function Name:
     *      rtl_switch_isUtpPort
     * Description:
     *      Check is logical port a UTP port
     * Input:
     *      logicalPort     - logical port ID
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Port ID is a UTP port
     *      RT_ERR_FAILED   - Port ID is not a UTP port
     *      RT_ERR_NOT_INIT - Not Initialize
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_isUtpPort(rtk_port_t logicalPort)
    {
        return rtk_switch_isUtpPort(logicalPort);
    }

    /* Function Name:
     *      rtl_switch_isExtPort
     * Description:
     *      Check is logical port a Extension port
     * Input:
     *      logicalPort     - logical port ID
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Port ID is a EXT port
     *      RT_ERR_FAILED   - Port ID is not a EXT port
     *      RT_ERR_NOT_INIT - Not Initialize
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_isExtPort(rtk_port_t logicalPort)
    {
        return rtk_switch_isExtPort(logicalPort);
    }

    /* Function Name:
     *      rtl_switch_isHsgPort
     * Description:
     *      Check is logical port a HSG port
     * Input:
     *      logicalPort     - logical port ID
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Port ID is a HSG port
     *      RT_ERR_FAILED   - Port ID is not a HSG port
     *      RT_ERR_NOT_INIT - Not Initialize
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_isHsgPort(rtk_port_t logicalPort)
    {
        return rtk_switch_isHsgPort(logicalPort);
    }

    /* Function Name:
     *      rtl_switch_isSgmiiPort
     * Description:
     *      Check is logical port a SGMII port
     * Input:
     *      logicalPort     - logical port ID
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Port ID is a SGMII port
     *      RT_ERR_FAILED   - Port ID is not a SGMII port
     *      RT_ERR_NOT_INIT - Not Initialize
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_isSgmiiPort(rtk_port_t logicalPort)
    {
        return rtk_switch_isSgmiiPort(logicalPort);
    }

    /* Function Name:
     *      rtl_switch_isCPUPort
     * Description:
     *      Check is logical port a CPU port
     * Input:
     *      logicalPort     - logical port ID
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Port ID is a CPU port
     *      RT_ERR_FAILED   - Port ID is not a CPU port
     *      RT_ERR_NOT_INIT - Not Initialize
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_isCPUPort(rtk_port_t logicalPort)
    {
        return rtk_switch_isCPUPort(logicalPort);
    }

    /* Function Name:
     *      rtl_switch_isComboPort
     * Description:
     *      Check is logical port a Combo port
     * Input:
     *      logicalPort     - logical port ID
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Port ID is a combo port
     *      RT_ERR_FAILED   - Port ID is not a combo port
     *      RT_ERR_NOT_INIT - Not Initialize
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_isComboPort(rtk_port_t logicalPort)
    {
        return rtk_switch_isComboPort(logicalPort);
    }

    /* Function Name:
     *      rtl_switch_ComboPort_get
     * Description:
     *      Get Combo port ID
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      Port ID of combo port
     * Note:
     *
     */
    rtk_uint32 rtl_switch_ComboPort_get()
    {
        return rtk_switch_ComboPort_get();
    }

    /* Function Name:
     *      rtl_switch_isPtpPort
     * Description:
     *      Check is logical port a PTP port
     * Input:
     *      logicalPort     - logical port ID
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - Port ID is a PTP port
     *      RT_ERR_FAILED   - Port ID is not a PTP port
     *      RT_ERR_NOT_INIT - Not Initialize
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_isPtpPort(rtk_port_t logicalPort)
    {
        return rtk_switch_isPtpPort(logicalPort);
    }

    /* Function Name:
     *      rtl_switch_port_L2P_get
     * Description:
     *      Get physical port ID
     * Input:
     *      logicalPort       - logical port ID
     * Output:
     *      None
     * Return:
     *      Physical port ID
     * Note:
     *
     */
    rtk_uint32 rtl_switch_port_L2P_get(rtk_port_t logicalPort)
    {
        return rtk_switch_port_L2P_get(logicalPort);
    }

    /* Function Name:
     *      rtl_switch_port_P2L_get
     * Description:
     *      Get logical port ID
     * Input:
     *      physicalPort       - physical port ID
     * Output:
     *      None
     * Return:
     *      logical port ID
     * Note:
     *
     */
    rtk_port_t rtl_switch_port_P2L_get(rtk_uint32 physicalPort)
    {
        return rtk_switch_port_P2L_get(physicalPort);
    }

    /* Function Name:
     *      rtl_switch_isPortMaskValid
     * Description:
     *      Check portmask is valid or not
     * Input:
     *      pPmask       - logical port mask
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - port mask is valid
     *      RT_ERR_FAILED       - port mask is not valid
     *      RT_ERR_NOT_INIT     - Not Initialize
     *      RT_ERR_NULL_POINTER - Null pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_isPortMaskValid(rtk_portmask_t *pPmask)
    {
        return rtk_switch_isPortMaskValid(pPmask);
    }

    /* Function Name:
     *      rtl_switch_isPortMaskUtp
     * Description:
     *      Check all ports in portmask are only UTP port
     * Input:
     *      pPmask       - logical port mask
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - Only UTP port in port mask
     *      RT_ERR_FAILED       - Not only UTP port in port mask
     *      RT_ERR_NOT_INIT     - Not Initialize
     *      RT_ERR_NULL_POINTER - Null pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_isPortMaskUtp(rtk_portmask_t *pPmask)
    {
        return rtk_switch_isPortMaskUtp(pPmask);
    }

    /* Function Name:
     *      rtl_switch_isPortMaskExt
     * Description:
     *      Check all ports in portmask are only EXT port
     * Input:
     *      pPmask       - logical port mask
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - Only EXT port in port mask
     *      RT_ERR_FAILED       - Not only EXT port in port mask
     *      RT_ERR_NOT_INIT     - Not Initialize
     *      RT_ERR_NULL_POINTER - Null pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_isPortMaskExt(rtk_portmask_t *pPmask)
    {
        return rtk_switch_isPortMaskExt(pPmask);
    }

    /* Function Name:
     *      rtl_switch_portmask_L2P_get
     * Description:
     *      Get physicl portmask from logical portmask
     * Input:
     *      pLogicalPmask       - logical port mask
     * Output:
     *      pPhysicalPortmask   - physical port mask
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_NOT_INIT     - Not Initialize
     *      RT_ERR_NULL_POINTER - Null pointer
     *      RT_ERR_PORT_MASK    - Error port mask
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_portmask_L2P_get(rtk_portmask_t *pLogicalPmask, rtk_uint32 *pPhysicalPortmask)
    {
        return rtk_switch_portmask_L2P_get(pLogicalPmask, pPhysicalPortmask);
    }

    /* Function Name:
     *      rtl_switch_portmask_P2L_get
     * Description:
     *      Get logical portmask from physical portmask
     * Input:
     *      physicalPortmask    - physical port mask
     * Output:
     *      pLogicalPmask       - logical port mask
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_NOT_INIT     - Not Initialize
     *      RT_ERR_NULL_POINTER - Null pointer
     *      RT_ERR_PORT_MASK    - Error port mask
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_portmask_P2L_get(rtk_uint32 physicalPortmask, rtk_portmask_t *pLogicalPmask)
    {
        return rtk_switch_portmask_P2L_get(physicalPortmask, pLogicalPmask);
    }

    /* Function Name:
     *      rtl_switch_phyPortMask_get
     * Description:
     *      Get physical portmask
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      0x00                - Not Initialize
     *      Other value         - Physical port mask
     * Note:
     *
     */
    rtk_uint32 rtl_switch_phyPortMask_get()
    {
        return rtk_switch_phyPortMask_get();
    }

    /* Function Name:
     *      rtl_switch_logPortMask_get
     * Description:
     *      Get Logical portmask
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_NOT_INIT     - Not Initialize
     *      RT_ERR_NULL_POINTER - Null pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_switch_logPortMask_get(rtk_portmask_t *pPortmask)
    {
        return rtk_switch_logPortMask_get(pPortmask);
    }

    /* Function Name:
     *      rtl_switch_init
     * Description:
     *      Set chip to default configuration enviroment
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      The API can set chip registers to default configuration for different release chip model.
     */
    rtk_api_ret_t rtl_switch_init()
    {
        return rtk_switch_init();
    }

    /* Function Name:
     *      rtl_switch_portMaxPktLen_set
     * Description:
     *      Set Max packet length
     * Input:
     *      port    - Port ID
     *      speed   - Speed
     *      cfgId   - Configuration ID
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Error Input
     * Note:
     */
    rtk_api_ret_t rtl_switch_portMaxPktLen_set(rtk_port_t port, rtk_switch_maxPktLen_linkSpeed_t speed, rtk_uint32 cfgId)
    {
        return rtk_switch_portMaxPktLen_set(port, speed, cfgId);
    }

    /* Function Name:
     *      rtl_switch_portMaxPktLen_get
     * Description:
     *      Get Max packet length
     * Input:
     *      port    - Port ID
     *      speed   - Speed
     * Output:
     *      pCfgId  - Configuration ID
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Error Input
     * Note:
     */
    rtk_api_ret_t rtl_switch_portMaxPktLen_get(rtk_port_t port, rtk_switch_maxPktLen_linkSpeed_t speed, rtk_uint32 *pCfgId)
    {
        return rtk_switch_portMaxPktLen_get(port, speed, pCfgId);
    }

    /* Function Name:
     *      rtl_switch_maxPktLenCfg_set
     * Description:
     *      Set Max packet length configuration
     * Input:
     *      cfgId   - Configuration ID
     *      pktLen  - Max packet length
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Error Input
     * Note:
     */
    rtk_api_ret_t rtl_switch_maxPktLenCfg_set(rtk_uint32 cfgId, rtk_uint32 pktLen)
    {
        return rtk_switch_maxPktLenCfg_set(cfgId, pktLen);
    }

    /* Function Name:
     *      rtl_switch_maxPktLenCfg_get
     * Description:
     *      Get Max packet length configuration
     * Input:
     *      cfgId   - Configuration ID
     *      pPktLen - Max packet length
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Error Input
     * Note:
     */
    rtk_api_ret_t rtl_switch_maxPktLenCfg_get(rtk_uint32 cfgId, rtk_uint32 *pPktLen)
    {
        return rtk_switch_maxPktLenCfg_get(cfgId, pPktLen);
    }

    /* Function Name:
     *      rtl_switch_greenEthernet_set
     * Description:
     *      Set all Ports Green Ethernet state.
     * Input:
     *      enable - Green Ethernet state.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK       - OK
     *      RT_ERR_FAILED   - Failed
     *      RT_ERR_SMI      - SMI access error
     *      RT_ERR_ENABLE   - Invalid enable input.
     * Note:
     *      This API can set all Ports Green Ethernet state.
     *      The configuration is as following:
     *      - DISABLE
     *      - ENABLE
     */
    rtk_api_ret_t rtl_switch_greenEthernet_set(rtk_enable_t enable)
    {
        return rtk_switch_greenEthernet_set(enable);
    }

    /* Function Name:
     *      rtl_switch_greenEthernet_get
     * Description:
     *      Get all Ports Green Ethernet state.
     * Input:
     *      None
     * Output:
     *      pEnable - Green Ethernet state.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      This API can get Green Ethernet state.
     */
    rtk_api_ret_t rtl_switch_greenEthernet_get(rtk_enable_t *pEnable)
    {
        return rtk_switch_greenEthernet_get(pEnable);
    }

    /* Function Name:
     *      rtl_switch_maxLogicalPort_get
     * Description:
     *      Get Max logical port ID
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      Max logical port
     * Note:
     *      This API can get max logical port
     */
    rtk_port_t rtl_switch_maxLogicalPort_get()
    {
        return rtk_switch_maxLogicalPort_get();
    }

    /* Function Name:
     *      rtl_switch_maxMeterId_get
     * Description:
     *      Get Max Meter ID
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      0x00                - Not Initialize
     *      Other value         - Max Meter ID
     * Note:
     *
     */
    rtk_uint32 rtl_switch_maxMeterId_get()
    {
        return rtk_switch_maxMeterId_get();
    }

    /* Function Name:
     *      rtl_switch_maxLutAddrNumber_get
     * Description:
     *      Get Max LUT Address number
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      0x00                - Not Initialize
     *      Other value         - Max LUT Address number
     * Note:
     *
     */
    rtk_uint32 rtl_switch_maxLutAddrNumber_get()
    {
        return rtk_switch_maxLutAddrNumber_get();
    }

    /* Function Name:
     *      rtl_switch_isValidTrunkGrpId
     * Description:
     *      Check if trunk group is valid or not
     * Input:
     *      grpId       - Group ID
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - Trunk Group ID is valid
     *      RT_ERR_LA_TRUNK_ID  - Trunk Group ID is not valid
     * Note:
     *
     */
    rtk_uint32 rtl_switch_isValidTrunkGrpId(rtk_uint32 grpId)
    {
        return rtk_switch_isValidTrunkGrpId(grpId);
    }
};

#endif