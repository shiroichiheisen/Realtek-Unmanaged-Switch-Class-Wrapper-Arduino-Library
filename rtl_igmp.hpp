#ifndef _rtl_igmp_hpp_
#define _rtl_igmp_hpp_

#include <Arduino.h>

extern "C"
{
#include "igmp.h"
#include "rtk_types.h"
}

class rtl_igmp
{
public:
    /* Function Name:
     *      rtl_igmp_init
     * Description:
     *      This API enables H/W IGMP and set a default initial configuration.
     * Input:
     *      None.
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      This API enables H/W IGMP and set a default initial configuration.
     */
    rtk_api_ret_t rtl_igmp_init()
    {
        return rtk_igmp_init();
    }

    /* Function Name:
     *      rtl_igmp_state_set
     * Description:
     *      This API set H/W IGMP state.
     * Input:
     *      enabled     - H/W IGMP state
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error parameter
     * Note:
     *      This API set H/W IGMP state.
     */
    rtk_api_ret_t rtl_igmp_state_set(rtk_enable_t enabled)
    {
        return rtk_igmp_state_set(enabled);
    }

    /* Function Name:
     *      rtl_igmp_state_get
     * Description:
     *      This API get H/W IGMP state.
     * Input:
     *      None.
     * Output:
     *      pEnabled        - H/W IGMP state
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error parameter
     * Note:
     *      This API set current H/W IGMP state.
     */
    rtk_api_ret_t rtl_igmp_state_get(rtk_enable_t *pEnabled)
    {
        return rtk_igmp_state_get(pEnabled);
    }

    /* Function Name:
     *      rtl_igmp_static_router_port_set
     * Description:
     *      Configure static router port
     * Input:
     *      pPortmask    - Static Port mask
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_PORT_MASK       - Error parameter
     * Note:
     *      This API set static router port
     */
    rtk_api_ret_t rtl_igmp_static_router_port_set(rtk_portmask_t *pPortmask)
    {
        return rtk_igmp_static_router_port_set(pPortmask);
    }

    /* Function Name:
     *      rtl_igmp_static_router_port_get
     * Description:
     *      Get static router port
     * Input:
     *      None.
     * Output:
     *      pPortmask       - Static port mask
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_PORT_MASK       - Error parameter
     * Note:
     *      This API get static router port
     */
    rtk_api_ret_t rtl_igmp_static_router_port_get(rtk_portmask_t *pPortmask)
    {
        return rtk_igmp_static_router_port_get(pPortmask);
    }

    /* Function Name:
     *      rtl_igmp_protocol_set
     * Description:
     *      set IGMP/MLD protocol action
     * Input:
     *      port        - Port ID
     *      protocol    - IGMP/MLD protocol
     *      action      - Per-port and per-protocol IGMP action seeting
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_PORT_MASK       - Error parameter
     * Note:
     *      This API set IGMP/MLD protocol action
     */
    rtk_api_ret_t rtl_igmp_protocol_set(rtk_port_t port, rtk_igmp_protocol_t protocol, rtk_igmp_action_t action)
    {
        return rtk_igmp_protocol_set(port, protocol, action);
    }

    /* Function Name:
     *      rtl_igmp_protocol_get
     * Description:
     *      set IGMP/MLD protocol action
     * Input:
     *      port        - Port ID
     *      protocol    - IGMP/MLD protocol
     *      action      - Per-port and per-protocol IGMP action seeting
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_PORT_MASK       - Error parameter
     * Note:
     *      This API set IGMP/MLD protocol action
     */
    rtk_api_ret_t rtl_igmp_protocol_get(rtk_port_t port, rtk_igmp_protocol_t protocol, rtk_igmp_action_t *pAction)
    {
        return rtk_igmp_protocol_get(port, protocol, pAction);
    }

    /* Function Name:
     *      rtl_igmp_fastLeave_set
     * Description:
     *      set IGMP/MLD FastLeave state
     * Input:
     *      state       - ENABLED: Enable FastLeave, DISABLED: disable FastLeave
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      This API set IGMP/MLD FastLeave state
     */
    rtk_api_ret_t rtl_igmp_fastLeave_set(rtk_enable_t state)
    {
        return rtk_igmp_fastLeave_set(state);
    }

    /* Function Name:
     *      rtl_igmp_fastLeave_get
     * Description:
     *      get IGMP/MLD FastLeave state
     * Input:
     *      None
     * Output:
     *      pState      - ENABLED: Enable FastLeave, DISABLED: disable FastLeave
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_NULL_POINTER    - NULL pointer
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      This API get IGMP/MLD FastLeave state
     */
    rtk_api_ret_t rtl_igmp_fastLeave_get(rtk_enable_t *pState)
    {
        return rtk_igmp_fastLeave_get(pState);
    }

    /* Function Name:
     *      rtl_igmp_maxGroup_set
     * Description:
     *      Set per port multicast group learning limit.
     * Input:
     *      port        - Port ID
     *      group       - The number of multicast group learning limit.
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_PORT_ID         - Error Port ID
     *      RT_ERR_OUT_OF_RANGE    - parameter out of range
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      This API set per port multicast group learning limit.
     */
    rtk_api_ret_t rtl_igmp_maxGroup_set(rtk_port_t port, rtk_uint32 group)
    {
        return rtk_igmp_maxGroup_set(port, group);
    }

    /* Function Name:
     *      rtl_igmp_maxGroup_get
     * Description:
     *      Get per port multicast group learning limit.
     * Input:
     *      port        - Port ID
     * Output:
     *      pGroup      - The number of multicast group learning limit.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_PORT_ID         - Error Port ID
     *      RT_ERR_NULL_POINTER    - Null pointer
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      This API get per port multicast group learning limit.
     */
    rtk_api_ret_t rtl_igmp_maxGroup_get(rtk_port_t port, rtk_uint32 *pGroup)
    {
        return rtk_igmp_maxGroup_get(port, pGroup);
    }

    /* Function Name:
     *      rtl_igmp_currentGroup_get
     * Description:
     *      Get per port multicast group learning count.
     * Input:
     *      port        - Port ID
     * Output:
     *      pGroup      - The number of multicast group learning count.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_PORT_ID         - Error Port ID
     *      RT_ERR_NULL_POINTER    - Null pointer
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     *      This API get per port multicast group learning count.
     */
    rtk_api_ret_t rtl_igmp_currentGroup_get(rtk_port_t port, rtk_uint32 *pGroup)
    {
        return rtk_igmp_currentGroup_get(port, pGroup);
    }

    /* Function Name:
     *      rtl_igmp_tableFullAction_set
     * Description:
     *      set IGMP/MLD Table Full Action
     * Input:
     *      action      - Table Full Action
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     */
    rtk_api_ret_t rtl_igmp_tableFullAction_set(rtk_igmp_tableFullAction_t action)
    {
        return rtk_igmp_tableFullAction_set(action);
    }

    /* Function Name:
     *      rtl_igmp_tableFullAction_get
     * Description:
     *      get IGMP/MLD Table Full Action
     * Input:
     *      None
     * Output:
     *      pAction     - Table Full Action
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_NULL_POINTER    - Null pointer
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     */
    rtk_api_ret_t rtl_igmp_tableFullAction_get(rtk_igmp_tableFullAction_t *pAction)
    {
        return rtk_igmp_tableFullAction_get(pAction);
    }

    /* Function Name:
     *      rtl_igmp_checksumErrorAction_set
     * Description:
     *      set IGMP/MLD Checksum Error Action
     * Input:
     *      action      - Checksum error Action
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     */
    rtk_api_ret_t rtl_igmp_checksumErrorAction_set(rtk_igmp_checksumErrorAction_t action)
    {
        return rtk_igmp_checksumErrorAction_set(action);
    }

    /* Function Name:
     *      rtl_igmp_checksumErrorAction_get
     * Description:
     *      get IGMP/MLD Checksum Error Action
     * Input:
     *      None
     * Output:
     *      pAction     - Checksum error Action
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_NULL_POINTER    - Null pointer
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     */
    rtk_api_ret_t rtl_igmp_checksumErrorAction_get(rtk_igmp_checksumErrorAction_t *pAction)
    {
        return rtk_igmp_checksumErrorAction_get(pAction);
    }

    /* Function Name:
     *      rtl_igmp_leaveTimer_set
     * Description:
     *      set IGMP/MLD Leave timer
     * Input:
     *      timer       - Leave timer
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     */
    rtk_api_ret_t rtl_igmp_leaveTimer_set(rtk_uint32 timer)
    {
        return rtk_igmp_leaveTimer_set(timer);
    }

    /* Function Name:
     *      rtl_igmp_leaveTimer_get
     * Description:
     *      get IGMP/MLD Leave timer
     * Input:
     *      None
     * Output:
     *      pTimer      - Leave Timer.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_NULL_POINTER    - Null pointer
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     */
    rtk_api_ret_t rtl_igmp_leaveTimer_get(rtk_uint32 *pTimer)
    {
        return rtk_igmp_leaveTimer_get(pTimer);
    }

    /* Function Name:
     *      rtl_igmp_queryInterval_set
     * Description:
     *      set IGMP/MLD Query Interval
     * Input:
     *      interval     - Query Interval
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     */
    rtk_api_ret_t rtl_igmp_queryInterval_set(rtk_uint32 interval)
    {
        return rtk_igmp_queryInterval_set(interval);
    }

    /* Function Name:
     *      rtl_igmp_queryInterval_get
     * Description:
     *      get IGMP/MLD Query Interval
     * Input:
     *      None.
     * Output:
     *      pInterval   - Query Interval
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_NULL_POINTER    - Null pointer
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     */
    rtk_api_ret_t rtl_igmp_queryInterval_get(rtk_uint32 *pInterval)
    {
        return rtk_igmp_queryInterval_get(pInterval);
    }

    /* Function Name:
     *      rtl_igmp_robustness_set
     * Description:
     *      set IGMP/MLD Robustness value
     * Input:
     *      robustness     - Robustness value
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     */
    rtk_api_ret_t rtl_igmp_robustness_set(rtk_uint32 robustness)
    {
        return rtk_igmp_robustness_set(robustness);
    }

    /* Function Name:
     *      rtl_igmp_robustness_get
     * Description:
     *      get IGMP/MLD Robustness value
     * Input:
     *      None
     * Output:
     *      pRobustness     - Robustness value.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_NULL_POINTER    - Null pointer
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     * Note:
     */
    rtk_api_ret_t rtl_igmp_robustness_get(rtk_uint32 *pRobustness)
    {
        return rtk_igmp_robustness_get(pRobustness);
    }

    /* Function Name:
     *      rtl_igmp_dynamicRouterPortAllow_set
     * Description:
     *      Configure dynamic router port allow option
     * Input:
     *      pPortmask    - Dynamic Port allow mask
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_PORT_MASK       - Error parameter
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_dynamicRouterPortAllow_set(rtk_portmask_t *pPortmask)
    {
        return rtk_igmp_dynamicRouterPortAllow_set(pPortmask);
    }

    /* Function Name:
     *      rtl_igmp_dynamicRouterPortAllow_get
     * Description:
     *      Get dynamic router port allow option
     * Input:
     *      None.
     * Output:
     *      pPortmask    - Dynamic Port allow mask
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_PORT_MASK       - Error parameter
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_dynamicRouterPortAllow_get(rtk_portmask_t *pPortmask)
    {
        return rtk_igmp_dynamicRouterPortAllow_get(pPortmask);
    }

    /* Function Name:
     *      rtl_igmp_dynamicRouterPort_get
     * Description:
     *      Get dynamic router port
     * Input:
     *      None.
     * Output:
     *      pDynamicRouterPort    - Dynamic Router Port
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_NULL_POINTER    - Null pointer
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_PORT_MASK       - Error parameter
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_dynamicRouterPort_get(rtk_igmp_dynamicRouterPort_t *pDynamicRouterPort)
    {
        return rtk_igmp_dynamicRouterPort_get(pDynamicRouterPort);
    }

    /* Function Name:
     *      rtl_igmp_suppressionEnable_set
     * Description:
     *      Configure IGMPv1/v2 & MLDv1 Report/Leave/Done suppression
     * Input:
     *      reportSuppression   - Report suppression
     *      leaveSuppression    - Leave suppression
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error Input
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_suppressionEnable_set(rtk_enable_t reportSuppression, rtk_enable_t leaveSuppression)
    {
        return rtk_igmp_suppressionEnable_set(reportSuppression, leaveSuppression);
    }

    /* Function Name:
     *      rtl_igmp_suppressionEnable_get
     * Description:
     *      Get IGMPv1/v2 & MLDv1 Report/Leave/Done suppression
     * Input:
     *      None
     * Output:
     *      pReportSuppression  - Report suppression
     *      pLeaveSuppression   - Leave suppression
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_NULL_POINTER    - Null pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_suppressionEnable_get(rtk_enable_t *pReportSuppression, rtk_enable_t *pLeaveSuppression)
    {
        return rtk_igmp_suppressionEnable_get(pReportSuppression, pLeaveSuppression);
    }

    /* Function Name:
     *      rtl_igmp_portRxPktEnable_set
     * Description:
     *      Configure IGMP/MLD RX Packet configuration
     * Input:
     *      port       - Port ID
     *      pRxCfg     - RX Packet Configuration
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_NULL_POINTER    - Null pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_portRxPktEnable_set(rtk_port_t port, rtk_igmp_rxPktEnable_t *pRxCfg)
    {
        return rtk_igmp_portRxPktEnable_set(port, pRxCfg);
    }

    /* Function Name:
     *      rtl_igmp_portRxPktEnable_get
     * Description:
     *      Get IGMP/MLD RX Packet configuration
     * Input:
     *      port       - Port ID
     *      pRxCfg     - RX Packet Configuration
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_NULL_POINTER    - Null pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_portRxPktEnable_get(rtk_port_t port, rtk_igmp_rxPktEnable_t *pRxCfg)
    {
        return rtk_igmp_portRxPktEnable_get(port, pRxCfg);
    }

    /* Function Name:
     *      rtl_igmp_groupInfo_get
     * Description:
     *      Get IGMP/MLD Group database
     * Input:
     *      indes       - Index (0~255)
     * Output:
     *      pGroup      - Group database information.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_NULL_POINTER    - Null pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_groupInfo_get(rtk_uint32 index, rtk_igmp_groupInfo_t *pGroup)
    {
        return rtk_igmp_groupInfo_get(index, pGroup);
    }

    /* Function Name:
     *      rtl_igmp_ReportLeaveFwdAction_set
     * Description:
     *      Set Report Leave packet forwarding action
     * Input:
     *      action      - Action
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error Input
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_ReportLeaveFwdAction_set(rtk_igmp_ReportLeaveFwdAct_t action)
    {
        return rtk_igmp_ReportLeaveFwdAction_set(action);
    }

    /* Function Name:
     *      rtl_igmp_ReportLeaveFwdAction_get
     * Description:
     *      Get Report Leave packet forwarding action
     * Input:
     *      action      - Action
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_NULL_POINTER    - Null Pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_ReportLeaveFwdAction_get(rtk_igmp_ReportLeaveFwdAct_t *pAction)
    {
        return rtk_igmp_ReportLeaveFwdAction_get(pAction);
    }

    /* Function Name:
     *      rtl_igmp_dropLeaveZeroEnable_set
     * Description:
     *      Set the function of droppping Leave packet with group IP = 0.0.0.0
     * Input:
     *      enabled      - Action 1: drop, 0:pass
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error Input
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_dropLeaveZeroEnable_set(rtk_enable_t enabled)
    {
        return rtk_igmp_dropLeaveZeroEnable_set(enabled);
    }

    /* Function Name:
     *      rtl_igmp_dropLeaveZeroEnable_get
     * Description:
     *      Get the function of droppping Leave packet with group IP = 0.0.0.0
     * Input:
     *      None
     * Output:
     *      pEnabled.   - Action 1: drop, 0:pass
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_NULL_POINTER    - Null Pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_dropLeaveZeroEnable_get(rtk_enable_t *pEnabled)
    {
        return rtk_igmp_dropLeaveZeroEnable_get(pEnabled);
    }

    /* Function Name:
     *      rtl_igmp_bypassGroupRange_set
     * Description:
     *      Set Bypass group
     * Input:
     *      group       - bypassed group
     *      enabled     - enabled 1: Bypassed, 0: not bypass
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error Input
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_bypassGroupRange_set(rtk_igmp_bypassGroup_t group, rtk_enable_t enabled)
    {
        return rtk_igmp_bypassGroupRange_set(group, enabled);
    }

    /* Function Name:
     *      rtl_igmp_bypassGroupRange_get
     * Description:
     *      get Bypass group
     * Input:
     *      group       - bypassed group
     * Output:
     *      pEnable     - enabled 1: Bypassed, 0: not bypass
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error Input
     *      RT_ERR_NULL_POINTER    - Null Pointer
     * Note:
     *
     */
    rtk_api_ret_t rtl_igmp_bypassGroupRange_get(rtk_igmp_bypassGroup_t group, rtk_enable_t *pEnable)
    {
        return rtk_igmp_bypassGroupRange_get(group, pEnable);
    }
};

#endif