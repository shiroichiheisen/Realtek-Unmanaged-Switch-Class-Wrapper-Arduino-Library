#ifndef _rtl_port_hpp_
#define _rtl_port_hpp_

extern "C"
{
#include "port.h"
#include "rtk_types.h"
}

class rtl_port
{
public:
    /* Function Name:
     *      rtl_port_phyAutoNegoAbility_set
     * Description:
     *      Set ethernet PHY auto-negotiation desired ability.
     * Input:
     *      port        - port id.
     *      pAbility    - Ability structure
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_PHY_REG_ID       - Invalid PHY address
     *      RT_ERR_INPUT            - Invalid input parameters.
     *      RT_ERR_BUSYWAIT_TIMEOUT - PHY access busy
     * Note:
     *      If Full_1000 bit is set to 1, the AutoNegotiation will be automatic set to 1. While both AutoNegotiation and Full_1000 are set to 0, the PHY speed and duplex selection will
     *      be set as following 100F > 100H > 10F > 10H priority sequence.
     */
    rtk_api_ret_t rtl_port_phyAutoNegoAbility_set(rtk_port_t port, rtk_port_phy_ability_t *pAbility)
    {
        return rtk_port_phyAutoNegoAbility_set(port, pAbility);
    }

    /* Function Name:
     *      rtl_port_phyAutoNegoAbility_get
     * Description:
     *      Get PHY ability through PHY registers.
     * Input:
     *      port - Port id.
     * Output:
     *      pAbility - Ability structure
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_PHY_REG_ID       - Invalid PHY address
     *      RT_ERR_INPUT            - Invalid input parameters.
     *      RT_ERR_BUSYWAIT_TIMEOUT - PHY access busy
     * Note:
     *      Get the capablity of specified PHY.
     */
    rtk_api_ret_t rtl_port_phyAutoNegoAbility_get(rtk_port_t port, rtk_port_phy_ability_t *pAbility)
    {
        return rtk_port_phyAutoNegoAbility_get(port, pAbility);
    }

    /* Function Name:
     *      rtl_port_phyForceModeAbility_set
     * Description:
     *      Set the port speed/duplex mode/pause/asy_pause in the PHY force mode.
     * Input:
     *      port        - port id.
     *      pAbility    - Ability structure
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_PHY_REG_ID       - Invalid PHY address
     *      RT_ERR_INPUT            - Invalid input parameters.
     *      RT_ERR_BUSYWAIT_TIMEOUT - PHY access busy
     * Note:
     *      While both AutoNegotiation and Full_1000 are set to 0, the PHY speed and duplex selection will
     *      be set as following 100F > 100H > 10F > 10H priority sequence.
     */
    rtk_api_ret_t rtl_port_phyForceModeAbility_set(rtk_port_t port, rtk_port_phy_ability_t *pAbility)
    {
        return rtk_port_phyForceModeAbility_set(port, pAbility);
    }

    /* Function Name:
     *      rtl_port_phyForceModeAbility_get
     * Description:
     *      Get PHY ability through PHY registers.
     * Input:
     *      port - Port id.
     * Output:
     *      pAbility - Ability structure
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_PHY_REG_ID       - Invalid PHY address
     *      RT_ERR_INPUT            - Invalid input parameters.
     *      RT_ERR_BUSYWAIT_TIMEOUT - PHY access busy
     * Note:
     *      Get the capablity of specified PHY.
     */
    rtk_api_ret_t rtl_port_phyForceModeAbility_get(rtk_port_t port, rtk_port_phy_ability_t *pAbility)
    {
        return rtk_port_phyForceModeAbility_get(port, pAbility);
    }

    /* Function Name:
     *      rtl_port_phyStatus_get
     * Description:
     *      Get ethernet PHY linking status
     * Input:
     *      port - Port id.
     * Output:
     *      linkStatus  - PHY link status
     *      speed       - PHY link speed
     *      duplex      - PHY duplex mode
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_PHY_REG_ID       - Invalid PHY address
     *      RT_ERR_INPUT            - Invalid input parameters.
     *      RT_ERR_BUSYWAIT_TIMEOUT - PHY access busy
     * Note:
     *      API will return auto negotiation status of phy.
     */
    rtk_api_ret_t rtl_port_phyStatus_get(rtk_port_t port, rtk_port_linkStatus_t *pLinkStatus, rtk_port_speed_t *pSpeed, rtk_port_duplex_t *pDuplex)
    {
        return rtk_port_phyStatus_get(port, pLinkStatus, pSpeed, pDuplex);
    }
    rtk_api_ret_t rtl_port_phyStatus_get(uint8_t port, uint8_t *pLinkStatus, uint8_t *pSpeed, uint8_t *pDuplex)
    {
        return rtk_port_phyStatus_get_uint8(port, pLinkStatus, pSpeed, pDuplex);
    }

    /* Function Name:
     *      rtl_port_macForceLink_set
     * Description:
     *      Set port force linking configuration.
     * Input:
     *      port            - port id.
     *      pPortability    - port ability configuration
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      This API can set Port/MAC force mode properties.
     */
    rtk_api_ret_t rtl_port_macForceLink_set(rtk_port_t port, rtk_port_mac_ability_t *pPortability)
    {
        return rtk_port_macForceLink_set(port, pPortability);
    }

    /* Function Name:
     *      rtl_port_macForceLink_get
     * Description:
     *      Get port force linking configuration.
     * Input:
     *      port - Port id.
     * Output:
     *      pPortability - port ability configuration
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This API can get Port/MAC force mode properties.
     */
    rtk_api_ret_t rtl_port_macForceLink_get(rtk_port_t port, rtk_port_mac_ability_t *pPortability)
    {
        return rtk_port_macForceLink_get(port, pPortability);
    }

    /* Function Name:
     *      rtl_port_macForceLinkExt_set
     * Description:
     *      Set al interface force linking configuration.
     * Input:
     *      port            - al port ID
     *      mode            - al interface mode
     *      pPortability    - port ability configuration
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This API can set al interface force mode properties.
     *      The al interface can be set to:
     *      - MODE_EXT_DISABLE,
     *      - MODE_EXT_RGMII,
     *      - MODE_EXT_MII_MAC,
     *      - MODE_EXT_MII_PHY,
     *      - MODE_EXT_TMII_MAC,
     *      - MODE_EXT_TMII_PHY,
     *      - MODE_EXT_GMII,
     *      - MODE_EXT_RMII_MAC,
     *      - MODE_EXT_RMII_PHY,
     *      - MODE_EXT_SGMII,
     *      - MODE_EXT_HSGMII,
     *      - MODE_EXT_1000X_100FX,
     *      - MODE_EXT_1000X,
     *      - MODE_EXT_100FX,
     */
    rtk_api_ret_t rtl_port_macForceLinkExt_set(rtk_port_t port, rtk_mode_ext_t mode, rtk_port_mac_ability_t *pPortability)
    {
        return rtk_port_macForceLinkExt_set(port, mode, pPortability);
    }

    /* Function Name:
     *      rtl_port_macForceLinkExt_get
     * Description:
     *      Set al interface force linking configuration.
     * Input:
     *      port            - al port ID
     * Output:
     *      pMode           - al interface mode
     *      pPortability    - port ability configuration
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This API can get al interface force mode properties.
     */
    rtk_api_ret_t rtl_port_macForceLinkExt_get(rtk_port_t port, rtk_mode_ext_t *pMode, rtk_port_mac_ability_t *pPortability)
    {
        return rtk_port_macForceLinkExt_get(port, pMode, pPortability);
    }

    /* Function Name:
     *      rtl_port_macStatus_get
     * Description:
     *      Get port link status.
     * Input:
     *      port - Port id.
     * Output:
     *      pPortstatus - port ability configuration
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      This API can get Port/PHY properties.
     */
    rtk_api_ret_t rtl_port_macStatus_get(rtk_port_t port, rtk_port_mac_ability_t *pPortstatus)
    {
        return rtk_port_macStatus_get(port, pPortstatus);
    }

    /* Function Name:
     *      rtl_port_macLocalLoopbackEnable_set
     * Description:
     *      Set Port Local Loopback. (Redirect TX to RX.)
     * Input:
     *      port    - Port id.
     *      enable  - Loopback state, 0:disable, 1:enable
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      This API can enable/disable Local loopback in MAC.
     *      For UTP port, This API will also enable the digital
     *      loopback bit in PHY register for sync of speed between
     *      PHY and MAC. For EXT port, users need to force the
     *      link state by themself.
     */
    rtk_api_ret_t rtl_port_macLocalLoopbackEnable_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_port_macLocalLoopbackEnable_set(port, enable);
    }

    /* Function Name:
     *      rtl_port_macLocalLoopbackEnable_get
     * Description:
     *      Get Port Local Loopback. (Redirect TX to RX.)
     * Input:
     *      port    - Port id.
     * Output:
     *      pEnable  - Loopback state, 0:disable, 1:enable
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_port_macLocalLoopbackEnable_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_port_macLocalLoopbackEnable_get(port, pEnable);
    }

    /* Function Name:
     *      rtl_port_phyReg_set
     * Description:
     *      Set PHY register data of the specific port.
     * Input:
     *      port    - port id.
     *      reg     - Register id
     *      regData - Register data
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_PHY_REG_ID       - Invalid PHY address
     *      RT_ERR_BUSYWAIT_TIMEOUT - PHY access busy
     * Note:
     *      This API can set PHY register data of the specific port.
     */
    rtk_api_ret_t rtl_port_phyReg_set(rtk_port_t port, rtk_port_phy_reg_t reg, rtk_port_phy_data_t value)
    {
        return rtk_port_phyReg_set(port, reg, value);
    }

    /* Function Name:
     *      rtl_port_phyReg_get
     * Description:
     *      Get PHY register data of the specific port.
     * Input:
     *      port    - Port id.
     *      reg     - Register id
     * Output:
     *      pData   - Register data
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_ID          - Invalid port number.
     *      RT_ERR_PHY_REG_ID       - Invalid PHY address
     *      RT_ERR_BUSYWAIT_TIMEOUT - PHY access busy
     * Note:
     *      This API can get PHY register data of the specific port.
     */
    rtk_api_ret_t rtl_port_phyReg_get(rtk_port_t port, rtk_port_phy_reg_t reg, rtk_port_phy_data_t *pData)
    {
        return rtk_port_phyReg_get(port, reg, pData);
    }

    /* Function Name:
     *      rtl_port_backpressureEnable_set
     * Description:
     *      Set the half duplex backpressure enable status of the specific port.
     * Input:
     *      port    - port id.
     *      enable  - Back pressure status.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_ENABLE       - Invalid enable input.
     * Note:
     *      This API can set the half duplex backpressure enable status of the specific port.
     *      The half duplex backpressure enable status of the port is as following:
     *      - DISABLE
     *      - ENABLE
     */
    rtk_api_ret_t rtl_port_backpressureEnable_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_port_backpressureEnable_set(port, enable);
    }

    /* Function Name:
     *      rtl_port_backpressureEnable_get
     * Description:
     *      Get the half duplex backpressure enable status of the specific port.
     * Input:
     *      port - Port id.
     * Output:
     *      pEnable - Back pressure status.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      This API can get the half duplex backpressure enable status of the specific port.
     *      The half duplex backpressure enable status of the port is as following:
     *      - DISABLE
     *      - ENABLE
     */
    rtk_api_ret_t rtl_port_backpressureEnable_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_port_backpressureEnable_get(port, pEnable);
    }

    /* Function Name:
     *      rtl_port_adminEnable_set
     * Description:
     *      Set port admin configuration of the specific port.
     * Input:
     *      port    - port id.
     *      enable  - Back pressure status.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_ENABLE       - Invalid enable input.
     * Note:
     *      This API can set port admin configuration of the specific port.
     *      The port admin configuration of the port is as following:
     *      - DISABLE
     *      - ENABLE
     */
    rtk_api_ret_t rtl_port_adminEnable_set(rtk_port_t port, rtk_enable_t enable)
    {
        return rtk_port_adminEnable_set(port, enable);
    }

    /* Function Name:
     *      rtl_port_adminEnable_get
     * Description:
     *      Get port admin configurationof the specific port.
     * Input:
     *      port - Port id.
     * Output:
     *      pEnable - Back pressure status.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      This API can get port admin configuration of the specific port.
     *      The port admin configuration of the port is as following:
     *      - DISABLE
     *      - ENABLE
     */
    rtk_api_ret_t rtl_port_adminEnable_get(rtk_port_t port, rtk_enable_t *pEnable)
    {
        return rtk_port_adminEnable_get(port, pEnable);
    }

    /* Function Name:
     *      rtl_port_isolation_set
     * Description:
     *      Set permitted port isolation portmask
     * Input:
     *      port         - port id.
     *      pPortmask    - Permit port mask
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     *      RT_ERR_PORT_MASK    - Invalid portmask.
     * Note:
     *      This API set the port mask that a port can trasmit packet to of each port
     *      A port can only transmit packet to ports included in permitted portmask
     */
    rtk_api_ret_t rtl_port_isolation_set(rtk_port_t port, rtk_portmask_t *pPortmask)
    {
        return rtk_port_isolation_set(port, pPortmask);
    }

    /* Function Name:
     *      rtl_port_isolation_get
     * Description:
     *      Get permitted port isolation portmask
     * Input:
     *      port - Port id.
     * Output:
     *      pPortmask - Permit port mask
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_PORT_ID      - Invalid port number.
     * Note:
     *      This API get the port mask that a port can trasmit packet to of each port
     *      A port can only transmit packet to ports included in permitted portmask
     */
    rtk_api_ret_t rtl_port_isolation_get(rtk_port_t port, rtk_portmask_t *pPortmask)
    {
        return rtk_port_isolation_get(port, pPortmask);
    }

    /* Function Name:
     *      rtl_port_rgmiiDelayExt_set
     * Description:
     *      Set RGMII interface delay value for TX and RX.
     * Input:
     *      txDelay - TX delay value, 1 for delay 2ns and 0 for no-delay
     *      rxDelay - RX delay value, 0~7 for delay setup.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This API can set al interface 2 RGMII delay.
     *      In TX delay, there are 2 selection: no-delay and 2ns delay.
     *      In RX dekay, there are 8 steps for delay tunning. 0 for no-delay, and 7 for maximum delay.
     *      Note. This API should be called before rtk_port_macForceLinkExt_set().
     */
    rtk_api_ret_t rtl_port_rgmiiDelayExt_set(rtk_port_t port, rtk_data_t txDelay, rtk_data_t rxDelay)
    {
        return rtk_port_rgmiiDelayExt_set(port, txDelay, rxDelay);
    }

    /* Function Name:
     *      rtl_port_rgmiiDelayExt_get
     * Description:
     *      Get RGMII interface delay value for TX and RX.
     * Input:
     *      None
     * Output:
     *      pTxDelay - TX delay value
     *      pRxDelay - RX delay value
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      This API can set al interface 2 RGMII delay.
     *      In TX delay, there are 2 selection: no-delay and 2ns delay.
     *      In RX dekay, there are 8 steps for delay tunning. 0 for n0-delay, and 7 for maximum delay.
     */
    rtk_api_ret_t rtl_port_rgmiiDelayExt_get(rtk_port_t port, rtk_data_t *pTxDelay, rtk_data_t *pRxDelay)
    {
        return rtk_port_rgmiiDelayExt_get(port, pTxDelay, pRxDelay);
    }

    /* Function Name:
     *      rtl_port_phyEnableAll_set
     * Description:
     *      Set all PHY enable status.
     * Input:
     *      enable - PHY Enable State.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_ENABLE       - Invalid enable input.
     * Note:
     *      This API can set all PHY status.
     *      The configuration of all PHY is as following:
     *      - DISABLE
     *      - ENABLE
     */
    rtk_api_ret_t rtl_port_phyEnableAll_set(rtk_enable_t enable)
    {
        return rtk_port_phyEnableAll_set(enable);
    }

    /* Function Name:
     *      rtl_port_phyEnableAll_get
     * Description:
     *      Get all PHY enable status.
     * Input:
     *      None
     * Output:
     *      pEnable - PHY Enable State.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     * Note:
     *      This API can set all PHY status.
     *      The configuration of all PHY is as following:
     *      - DISABLE
     *      - ENABLE
     */
    rtk_api_ret_t rtl_port_phyEnableAll_get(rtk_enable_t *pEnable)
    {
        return rtk_port_phyEnableAll_get(pEnable);
    }

    /* Function Name:
     *      rtl_port_efid_set
     * Description:
     *      Set port-based enhanced filtering database
     * Input:
     *      port - Port id.
     *      efid - Specified enhanced filtering database.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_L2_FID - Invalid fid.
     *      RT_ERR_INPUT - Invalid input parameter.
     *      RT_ERR_PORT_ID - Invalid port ID.
     * Note:
     *      The API can set port-based enhanced filtering database.
     */
    rtk_api_ret_t rtl_port_efid_set(rtk_port_t port, rtk_data_t efid)
    {
        return rtk_port_efid_set(port, efid);
    }

    /* Function Name:
     *      rtl_port_efid_get
     * Description:
     *      Get port-based enhanced filtering database
     * Input:
     *      port - Port id.
     * Output:
     *      pEfid - Specified enhanced filtering database.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT - Invalid input parameters.
     *      RT_ERR_PORT_ID - Invalid port ID.
     * Note:
     *      The API can get port-based enhanced filtering database status.
     */
    rtk_api_ret_t rtl_port_efid_get(rtk_port_t port, rtk_data_t *pEfid)
    {
        return rtk_port_efid_get(port, pEfid);
    }

    /* Function Name:
     *      rtl_port_phyComboPortMedia_set
     * Description:
     *      Set Combo port media type
     * Input:
     *      port    - Port id. (Should be Port 4)
     *      media   - Media (COPPER or FIBER)
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_INPUT            - Invalid input parameters.
     *      RT_ERR_PORT_ID          - Invalid port ID.
     * Note:
     *      The API can Set Combo port media type.
     */
    rtk_api_ret_t rtl_port_phyComboPortMedia_set(rtk_port_t port, rtk_port_media_t media)
    {
        return rtk_port_phyComboPortMedia_set(port, media);
    }

    /* Function Name:
     *      rtl_port_phyComboPortMedia_get
     * Description:
     *      Get Combo port media type
     * Input:
     *      port    - Port id. (Should be Port 4)
     * Output:
     *      pMedia  - Media (COPPER or FIBER)
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_INPUT            - Invalid input parameters.
     *      RT_ERR_PORT_ID          - Invalid port ID.
     * Note:
     *      The API can Set Combo port media type.
     */
    rtk_api_ret_t rtl_port_phyComboPortMedia_get(rtk_port_t port, rtk_port_media_t *pMedia)
    {
        return rtk_port_phyComboPortMedia_get(port, pMedia);
    }

    /* Function Name:
     *      rtl_port_rtctEnable_set
     * Description:
     *      Enable RTCT test
     * Input:
     *      pPortmask    - Port mask of RTCT enabled port
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_MASK        - Invalid port mask.
     * Note:
     *      The API can enable RTCT Test
     */
    rtk_api_ret_t rtl_port_rtctEnable_set(rtk_portmask_t *pPortmask)
    {
        return rtk_port_rtctEnable_set(pPortmask);
    }

    /* Function Name:
     *      rtl_port_rtctDisable_set
     * Description:
     *      Disable RTCT test
     * Input:
     *      pPortmask    - Port mask of RTCT disabled port
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK               - OK
     *      RT_ERR_FAILED           - Failed
     *      RT_ERR_SMI              - SMI access error
     *      RT_ERR_PORT_MASK        - Invalid port mask.
     * Note:
     *      The API can disable RTCT Test
     */
    rtk_api_ret_t rtl_port_rtctDisable_set(rtk_portmask_t *pPortmask)
    {
        return rtk_port_rtctDisable_set(pPortmask);
    }

    /* Function Name:
     *      rtl_port_rtctResult_get
     * Description:
     *      Get the result of RTCT test
     * Input:
     *      port        - Port ID
     * Output:
     *      pRtctResult - The result of RTCT result
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port ID.
     *      RT_ERR_PHY_RTCT_NOT_FINISH  - Testing does not finish.
     * Note:
     *      The API can get RTCT test result.
     *      RTCT test may takes 4.8 seconds to finish its test at most.
     *      Thus, if this API return RT_ERR_PHY_RTCT_NOT_FINISH or
     *      other error code, the result can not be referenced and
     *      user should call this API again until this API returns
     *      a RT_ERR_OK.
     *      The result is stored at pRtctResult->ge_result
     *      pRtctResult->linkType is unused.
     *      The unit of channel length is 2.5cm. Ex. 300 means 300 * 2.5 = 750cm = 7.5M
     */
    rtk_api_ret_t rtl_port_rtctResult_get(rtk_port_t port, rtk_rtctResult_t *pRtctResult)
    {
        return rtk_port_rtctResult_get(port, pRtctResult);
    }

    /* Function Name:
     *      rtl_port_sds_reset
     * Description:
     *      Reset Serdes
     * Input:
     *      port        - Port ID
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port ID.
     * Note:
     *      The API can reset Serdes
     */
    rtk_api_ret_t rtl_port_sds_reset(rtk_port_t port)
    {
        return rtk_port_sds_reset(port);
    }

    /* Function Name:
     *      rtl_port_sgmiiLinkStatus_get
     * Description:
     *      Get SGMII status
     * Input:
     *      port        - Port ID
     * Output:
     *      pSignalDetect   - Signal detect
     *      pSync           - Sync
     *      pLink           - Link
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port ID.
     * Note:
     *      The API can reset Serdes
     */
    rtk_api_ret_t rtl_port_sgmiiLinkStatus_get(rtk_port_t port, rtk_data_t *pSignalDetect, rtk_data_t *pSync, rtk_port_linkStatus_t *pLink)
    {
        return rtk_port_sgmiiLinkStatus_get(port, pSignalDetect, pSync, pLink);
    }
    rtk_api_ret_t rtl_port_sgmiiLinkStatus_get(rtk_uint8 port, rtk_uint8 *pSignalDetect, rtk_uint8 *pSync, rtk_uint8 *pLink)
    {
        return rtk_port_sgmiiLinkStatus_get_uint8(port, pSignalDetect, pSync, pLink);
    }

    /* Function Name:
     *      rtl_port_sgmiiNway_set
     * Description:
     *      Configure SGMII/HSGMII port Nway state
     * Input:
     *      port        - Port ID
     *      state       - Nway state
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port ID.
     * Note:
     *      The API configure SGMII/HSGMII port Nway state
     */
    rtk_api_ret_t rtl_port_sgmiiNway_set(rtk_port_t port, rtk_enable_t state)
    {
        return rtk_port_sgmiiNway_set(port, state);
    }

    /* Function Name:
     *      rtl_port_sgmiiNway_get
     * Description:
     *      Get SGMII/HSGMII port Nway state
     * Input:
     *      port        - Port ID
     * Output:
     *      pState      - Nway state
     * Return:
     *      RT_ERR_OK                   - OK
     *      RT_ERR_FAILED               - Failed
     *      RT_ERR_SMI                  - SMI access error
     *      RT_ERR_PORT_ID              - Invalid port ID.
     * Note:
     *      The API can get SGMII/HSGMII port Nway state
     */
    rtk_api_ret_t rtl_port_sgmiiNway_get(rtk_port_t port, rtk_enable_t *pState)
    {
        return rtk_port_sgmiiNway_get(port, pState);
    }
};

#endif