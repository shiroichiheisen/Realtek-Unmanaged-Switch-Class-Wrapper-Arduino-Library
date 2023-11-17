#ifndef _rtl_dot1x_hpp_
#define _rtl_dot1x_hpp_

#include <Arduino.h>

extern "C"
{
#include "dot1x.h"
#include "rtk_types.h"
}

class rtl_dot1x
{
public:
    /* Function Name:
     *      rtl_dot1x_unauthPacketOper_set
     * Description:
     *      Set 802.1x unauth action configuration.
     * Input:
     *      port            - Port id.
     *      unauth_action   - 802.1X unauth action.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_INPUT        - Invalid input parameter.
     * Note:
     *      This API can set 802.1x unauth action configuration.
     *      The unauth action is as following:
     *      - DOT1X_ACTION_DROP
     *      - DOT1X_ACTION_TRAP2CPU
     *      - DOT1X_ACTION_GUESTVLAN
     */
    rtk_api_ret_t rtl_dot1x_unauthPacketOper_set(rtk_port_t port, rtk_dot1x_unauth_action_t unauth_action)
    {
        return rtk_dot1x_unauthPacketOper_set(port, unauth_action);
    }

    /* Function Name:
     *      rtl_dot1x_unauthPacketOper_get
     * Description:
     *      Get 802.1x unauth action configuration.
     * Input:
     *      port - Port id.
     * Output:
     *      pUnauth_action - 802.1X unauth action.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      This API can get 802.1x unauth action configuration.
     *      The unauth action is as following:
     *      - DOT1X_ACTION_DROP
     *      - DOT1X_ACTION_TRAP2CPU
     *      - DOT1X_ACTION_GUESTVLAN
     */
    rtk_api_ret_t rtl_dot1x_unauthPacketOper_get(rtk_port_t port, rtk_dot1x_unauth_action_t *pUnauth_action)
    {
        return rtk_dot1x_unauthPacketOper_get(port, pUnauth_action);
    }

    /* Function Name:
     *      rtl_dot1x_eapolFrame2CpuEnable_set
     * Description:
     *      Set 802.1x EAPOL packet trap to CPU configuration
     * Input:
     *      enable - The status of 802.1x EAPOL packet.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_ENABLE       - Invalid enable input.
     * Note:
     *      To support 802.1x authentication functionality, EAPOL frame (ether type = 0x888E) has to
     *      be trapped to CPU.
     *      The status of EAPOL frame trap to CPU is as following:
     *      - DISABLED
     *      - ENABLED
     */
    rtk_api_ret_t rtl_dot1x_eapolFrame2CpuEnable_set(rtk_enable_t enable)
    {
        return rtk_dot1x_eapolFrame2CpuEnable_set(enable);
    }

    /* Function Name:
     *      rtl_dot1x_eapolFrame2CpuEnable_get
     * Description:
     *      Get 802.1x EAPOL packet trap to CPU configuration
     * Input:
     *      None
     * Output:
     *      pEnable - The status of 802.1x EAPOL packet.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      To support 802.1x authentication functionality, EAPOL frame (ether type = 0x888E) has to
     *      be trapped to CPU.
     *      The status of EAPOL frame trap to CPU is as following:
     *      - DISABLED
     *      - ENABLED
     */
    rtk_api_ret_t rtl_dot1x_eapolFrame2CpuEnable_get(rtk_enable_t *pEnable)
    {
        return rtk_dot1x_eapolFrame2CpuEnable_get(pEnable);
    }

    /* Function Name:
     *      rtl_dot1x_portBasedEnable_set
     * Description:
     *      Set 802.1x port-based enable configuration
     * Input:
     *      port - Port id.
     *      enable - The status of 802.1x port.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port number.
     *      RT_ERR_ENABLE               - Invalid enable input.
     *      RT_ERR_DOT1X_PORTBASEDPNEN  - 802.1X port-based enable error
     * Note:
     *      The API can update the port-based port enable register content. If a port is 802.1x
     *      port based network access control "enabled", it should be authenticated so packets
     *      from that port won't be dropped or trapped to CPU.
     *      The status of 802.1x port-based network access control is as following:
     *      - DISABLED
     *      - ENABLED
     */
    rtk_api_ret_t rtl_dot1x_portBasedEnable_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_dot1x_portBasedEnable_set(port, enable);
    }

    /* Function Name:
     *      rtl_dot1x_portBasedEnable_get
     * Description:
     *      Get 802.1x port-based enable configuration
     * Input:
     *      port - Port id.
     * Output:
     *      pEnable - The status of 802.1x port.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get the 802.1x port-based port status.
     */
    rtk_api_ret_t rtl_dot1x_portBasedEnable_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_dot1x_portBasedEnable_get(port, pEnable);
    }

    /* Function Name:
     *      rtl_dot1x_portBasedAuthStatus_set
     * Description:
     *      Set 802.1x port-based auth. port configuration
     * Input:
     *      port - Port id.
     *      port_auth - The status of 802.1x port.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port number.
     *     RT_ERR_DOT1X_PORTBASEDAUTH   - 802.1X port-based auth error
     * Note:
     *      The authenticated status of 802.1x port-based network access control is as following:
     *      - UNAUTH
     *      - AUTH
     */
    rtk_api_ret_t rtl_dot1x_portBasedAuthStatus_set(rtk_port_t port, rtk_dot1x_auth_status_t port_auth)
    {
        return rtk_dot1x_portBasedAuthStatus_set(port, port_auth);
    }

    /* Function Name:
     *      rtl_dot1x_portBasedAuthStatus_get
     * Description:
     *      Get 802.1x port-based auth. port configuration
     * Input:
     *      port - Port id.
     * Output:
     *      pPort_auth - The status of 802.1x port.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get 802.1x port-based port auth.information.
     */
    rtk_api_ret_t rtl_dot1x_portBasedAuthStatus_get(rtk_port_t port, rtk_dot1x_auth_status_t *pPort_auth)
    {
        return rtk_dot1x_portBasedAuthStatus_get(port, pPort_auth);
    }

    /* Function Name:
     *      rtl_dot1x_portBasedDirection_set
     * Description:
     *      Set 802.1x port-based operational direction configuration
     * Input:
     *      port            - Port id.
     *      port_direction  - Operation direction
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port number.
     *      RT_ERR_DOT1X_PORTBASEDOPDIR - 802.1X port-based operation direction error
     * Note:
     *      The operate controlled direction of 802.1x port-based network access control is as following:
     *      - BOTH
     *      - IN
     */
    rtk_api_ret_t rtl_dot1x_portBasedDirection_set(rtk_port_t port, rtk_dot1x_direction_t port_direction)
    {
        return rtk_dot1x_portBasedDirection_set(port, port_direction);
    }

    /* Function Name:
     *      rtl_dot1x_portBasedDirection_get
     * Description:
     *      Get 802.1X port-based operational direction configuration
     * Input:
     *      port - Port id.
     * Output:
     *      pPort_direction - Operation direction
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can get 802.1x port-based operational direction information.
     */
    rtk_api_ret_t rtl_dot1x_portBasedDirection_get(rtk_port_t port, rtk_dot1x_direction_t *pPort_direction)
    {
        return rtk_dot1x_portBasedDirection_get(port, pPort_direction);
    }

    /* Function Name:
     *      rtl_dot1x_macBasedEnable_set
     * Description:
     *      Set 802.1x mac-based port enable configuration
     * Input:
     *      port - Port id.
     *      enable - The status of 802.1x port.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port number.
     *      RT_ERR_ENABLE               - Invalid enable input.
     *      RT_ERR_DOT1X_MACBASEDPNEN   - 802.1X mac-based enable error
     * Note:
     *      If a port is 802.1x MAC based network access control "enabled", the incoming packets should
     *       be authenticated so packets from that port won't be dropped or trapped to CPU.
     *      The status of 802.1x MAC-based network access control is as following:
     *      - DISABLED
     *      - ENABLED
     */
    rtk_api_ret_t rtl_dot1x_macBasedEnable_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_dot1x_macBasedEnable_set(port, enable);
    }

    /* Function Name:
     *      rtl_dot1x_macBasedEnable_get
     * Description:
     *      Get 802.1x mac-based port enable configuration
     * Input:
     *      port - Port id.
     * Output:
     *      pEnable - The status of 802.1x port.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      If a port is 802.1x MAC based network access control "enabled", the incoming packets should
     *      be authenticated so packets from that port wont be dropped or trapped to CPU.
     *      The status of 802.1x MAC-based network access control is as following:
     *      - DISABLED
     *      - ENABLED
     */
    rtk_api_ret_t rtl_dot1x_macBasedEnable_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_dot1x_macBasedEnable_get(port, pEnable);
    }

    /* Function Name:
     *      rtl_dot1x_macBasedAuthMac_add
     * Description:
     *      Add an authenticated MAC to ASIC
     * Input:
     *      port        - Port id.
     *      pAuth_mac   - The authenticated MAC.
     *      fid         - filtering database.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port number.
     *      RT_ERR_ENABLE               - Invalid enable input.
     *      RT_ERR_DOT1X_MACBASEDPNEN   - 802.1X mac-based enable error
     * Note:
     *      The API can add a 802.1x authenticated MAC address to port. If the MAC does not exist in LUT,
     *      user can't add this MAC to auth status.
     */
    rtk_api_ret_t rtl_dot1x_macBasedAuthMac_add(rtk_port_t port, rtk_mac_t *pAuth_mac, rtk_fid_t fid)
    {
        return rtk_dot1x_macBasedAuthMac_add(port, pAuth_mac, fid);
    }

    /* Function Name:
     *      rtl_dot1x_macBasedAuthMac_del
     * Description:
     *      Delete an authenticated MAC to ASIC
     * Input:
     *      port - Port id.
     *      pAuth_mac - The authenticated MAC.
     *      fid - filtering database.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_MAC          - Invalid MAC address.
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      The API can delete a 802.1x authenticated MAC address to port. It only change the auth status of
     *      the MAC and won't delete it from LUT.
     */
    rtk_api_ret_t rtl_dot1x_macBasedAuthMac_del(rtk_port_t port, rtk_mac_t *pAuth_mac, rtk_fid_t fid)
    {
        return rtk_dot1x_macBasedAuthMac_del(port, pAuth_mac, fid);
    }

    /* Function Name:
     *      rtl_dot1x_macBasedDirection_set
     * Description:
     *      Set 802.1x mac-based operational direction configuration
     * Input:
     *      mac_direction - Operation direction
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_INPUT                - Invalid input parameter.
     *      RT_ERR_DOT1X_MACBASEDOPDIR  - 802.1X mac-based operation direction error
     * Note:
     *      The operate controlled direction of 802.1x mac-based network access control is as following:
     *      - BOTH
     *      - IN
     */
    rtk_api_ret_t rtl_dot1x_macBasedDirection_set(rtk_dot1x_direction_t mac_direction)
    {
        return rtk_dot1x_macBasedDirection_set(mac_direction);
    }

    /* Function Name:
     *      rtl_dot1x_macBasedDirection_get
     * Description:
     *      Get 802.1x mac-based operational direction configuration
     * Input:
     *      port - Port id.
     * Output:
     *      pMac_direction - Operation direction
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can get 802.1x mac-based operational direction information.
     */
    rtk_api_ret_t rtl_dot1x_macBasedDirection_get(rtk_dot1x_direction_t *pMac_direction)
    {
        return rtk_dot1x_macBasedDirection_get(pMac_direction);
    }

    /* Function Name:
     *      rtl_dot1x_guestVlan_set
     * Description:
     *      Set 802.1x guest VLAN configuration
     * Input:
     *      vid - 802.1x guest VLAN ID
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameter.
     * Note:
     *      The operate controlled 802.1x guest VLAN
     */
    rtk_api_ret_t rtl_dot1x_guestVlan_set(rtk_vlan_t vid)
    {
        return rtk_dot1x_guestVlan_set(vid);
    }

    /* Function Name:
     *      rtl_dot1x_guestVlan_get
     * Description:
     *      Get 802.1x guest VLAN configuration
     * Input:
     *      None
     * Output:
     *      pVid - 802.1x guest VLAN ID
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can get 802.1x guest VLAN information.
     */
    rtk_api_ret_t rtl_dot1x_guestVlan_get(rtk_vlan_t *pVid)
    {
        return rtk_dot1x_guestVlan_get(pVid);
    }

    /* Function Name:
     *      rtl_dot1x_guestVlan2Auth_set
     * Description:
     *      Set 802.1x guest VLAN to auth host configuration
     * Input:
     *      enable - The status of guest VLAN to auth host.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameter.
     * Note:
     *      The operational direction of 802.1x guest VLAN to auth host control is as following:
     *      - ENABLED
     *      - DISABLED
     */
    rtk_api_ret_t rtl_dot1x_guestVlan2Auth_set(rtk_enable_t enable)
    {
        return rtk_dot1x_guestVlan2Auth_set(enable);
    }

    /* Function Name:
     *      rtl_dot1x_guestVlan2Auth_get
     * Description:
     *      Get 802.1x guest VLAN to auth host configuration
     * Input:
     *      None
     * Output:
     *      pEnable - The status of guest VLAN to auth host.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can get 802.1x guest VLAN to auth host information.
     */
    rtk_api_ret_t rtl_dot1x_guestVlan2Auth_get(rtk_enable_t *pEnable)
    {
        return rtk_dot1x_guestVlan2Auth_get(pEnable);
    }
};

#endif