#ifndef _rtl_oam_hpp_
#define _rtl_oam_hpp_

#include <Arduino.h>

extern "C"
{
#include "oam.h"
#include "rtk_types.h"
}

class rtl_oam
{
public:
    /* Function Name:
     *      rtl_oam_init
     * Description:
     *      Initialize oam module.
     * Input:
     *      None
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     * Note:
     *      Must initialize oam module before calling any oam APIs.
     */
    rtk_api_ret_t rtl_oam_init();

    /* Function Name:
     *      rtl_oam_state_set
     * Description:
     *      This API set OAM state.
     * Input:
     *      enabled     -OAMstate
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error parameter
     * Note:
     *      This API set OAM state.
     */
    rtk_api_ret_t rtl_oam_state_set(rtk_enable_t enabled);

    /* Function Name:
     *      rtl_oam_state_get
     * Description:
     *      This API get OAM state.
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
     *      This API set current OAM state.
     */
    rtk_api_ret_t rtl_oam_state_get(rtk_enable_t *pEnabled);

    /* Module Name : OAM */

    /* Function Name:
     *      rtl_oam_parserAction_set
     * Description:
     *      Set OAM parser action
     * Input:
     *      port    - port id
     *      action  - parser action
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT_ID      - invalid port id
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_oam_parserAction_set(rtk_port_t port, rtk_oam_parser_act_t action);

    /* Function Name:
     *      rtl_oam_parserAction_get
     * Description:
     *      Get OAM parser action
     * Input:
     *      port    - port id
     * Output:
     *      pAction  - parser action
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT_ID      - invalid port id
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_oam_parserAction_get(rtk_port_t port, rtk_oam_parser_act_t *pAction);

    /* Function Name:
     *      rtl_oam_multiplexerAction_set
     * Description:
     *      Set OAM multiplexer action
     * Input:
     *      port    - port id
     *      action  - parser action
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT_ID      - invalid port id
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_oam_multiplexerAction_set(rtk_port_t port, rtk_oam_multiplexer_act_t action);

    /* Function Name:
     *      rtl_oam_multiplexerAction_get
     * Description:
     *      Get OAM multiplexer action
     * Input:
     *      port    - port id
     * Output:
     *      pAction  - parser action
     * Return:
     *      RT_ERR_OK
     *      RT_ERR_FAILED
     *      RT_ERR_PORT_ID      - invalid port id
     * Note:
     *      None
     */
    rtk_api_ret_t rtl_oam_multiplexerAction_get(rtk_port_t port, rtk_oam_multiplexer_act_t *pAction);
};

#endif