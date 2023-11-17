#ifndef _rtl_led_hpp_
#define _rtl_led_hpp_

#include <Arduino.h>

extern "C"
{
#include "led.h"
#include "rtk_types.h"
}

class rtl_led
{
public:
    /* Function Name:
     *      rtl_led_enable_set
     * Description:
     *      Set Led enable congiuration
     * Input:
     *      group       - LED group id.
     *      pPortmask    - LED enable port mask.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can be used to enable LED per port per group.
     */
    rtk_api_ret_t rtl_led_enable_set(rtk_led_group_t group, rtk_portmask_t *pPortmask);

    /* Function Name:
     *      rtl_led_enable_get
     * Description:
     *      Get Led enable congiuration
     * Input:
     *      group - LED group id.
     * Output:
     *      pPortmask - LED enable port mask.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can be used to get LED enable status.
     */
    rtk_api_ret_t rtl_led_enable_get(rtk_led_group_t group, rtk_portmask_t *pPortmask);

    /* Function Name:
     *      rtl_led_operation_set
     * Description:
     *      Set Led operation mode
     * Input:
     *      mode - LED operation mode.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can set Led operation mode.
     *      The modes that can be set are as following:
     *      - LED_OP_SCAN,
     *      - LED_OP_PARALLEL,
     *      - LED_OP_SERIAL,
     */
    rtk_api_ret_t rtl_led_operation_set(rtk_led_operation_t mode);

    /* Function Name:
     *      rtl_led_operation_get
     * Description:
     *      Get Led operation mode
     * Input:
     *      None
     * Output:
     *      pMode - Support LED operation mode.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can get Led operation mode.
     *      The modes that can be set are as following:
     *      - LED_OP_SCAN,
     *      - LED_OP_PARALLEL,
     *      - LED_OP_SERIAL,
     */
    rtk_api_ret_t rtl_led_operation_get(rtk_led_operation_t *pMode);

    /* Function Name:
     *      rtl_led_modeForce_set
     * Description:
     *      Set Led group to congiuration force mode
     * Input:
     *      port    - port ID
     *      group   - Support LED group id.
     *      mode    - Support LED force mode.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Error Port ID
     * Note:
     *      The API can force to one force mode.
     *      The force modes that can be set are as following:
     *      - LED_FORCE_NORMAL,
     *      - LED_FORCE_BLINK,
     *      - LED_FORCE_OFF,
     *      - LED_FORCE_ON.
     */
    rtk_api_ret_t rtl_led_modeForce_set(rtk_port_t port, rtk_led_group_t group, rtk_led_force_mode_t mode);

    /* Function Name:
     *      rtl_led_modeForce_get
     * Description:
     *      Get Led group to congiuration force mode
     * Input:
     *      port  - port ID
     *      group - Support LED group id.
     *      pMode - Support LED force mode.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     *      RT_ERR_PORT_ID      - Error Port ID
     * Note:
     *      The API can get forced Led group mode.
     *      The force modes that can be set are as following:
     *      - LED_FORCE_NORMAL,
     *      - LED_FORCE_BLINK,
     *      - LED_FORCE_OFF,
     *      - LED_FORCE_ON.
     */
    rtk_api_ret_t rtl_led_modeForce_get(rtk_port_t port, rtk_led_group_t group, rtk_led_force_mode_t *pMode);

    /* Function Name:
     *      rtl_led_blinkRate_set
     * Description:
     *      Set LED blinking rate
     * Input:
     *      blinkRate - blinking rate.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      ASIC support 6 types of LED blinking rates at 43ms, 84ms, 120ms, 170ms, 340ms and 670ms.
     */
    rtk_api_ret_t rtl_led_blinkRate_set(rtk_led_blink_rate_t blinkRate);

    /* Function Name:
     *      rtl_led_blinkRate_get
     * Description:
     *      Get LED blinking rate at mode 0 to mode 3
     * Input:
     *      None
     * Output:
     *      pBlinkRate - blinking rate.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      There are  6 types of LED blinking rates at 43ms, 84ms, 120ms, 170ms, 340ms and 670ms.
     */
    rtk_api_ret_t rtl_led_blinkRate_get(rtk_led_blink_rate_t *pBlinkRate);

    /* Function Name:
     *      rtl_led_groupConfig_set
     * Description:
     *      Set per group Led to congiuration mode
     * Input:
     *      group   - LED group.
     *      config  - LED configuration
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can set LED indicated information configuration for each LED group with 1 to 1 led mapping to each port.
     *      - Definition  LED Statuses      Description
     *      - 0000        LED_Off           LED pin Tri-State.
     *      - 0001        Dup/Col           Collision, Full duplex Indicator.
     *      - 0010        Link/Act          Link, Activity Indicator.
     *      - 0011        Spd1000           1000Mb/s Speed Indicator.
     *      - 0100        Spd100            100Mb/s Speed Indicator.
     *      - 0101        Spd10             10Mb/s Speed Indicator.
     *      - 0110        Spd1000/Act       1000Mb/s Speed/Activity Indicator.
     *      - 0111        Spd100/Act        100Mb/s Speed/Activity Indicator.
     *      - 1000        Spd10/Act         10Mb/s Speed/Activity Indicator.
     *      - 1001        Spd100 (10)/Act   10/100Mb/s Speed/Activity Indicator.
     *      - 1010        LoopDetect        LoopDetect Indicator.
     *      - 1011        EEE               EEE Indicator.
     *      - 1100        Link/Rx           Link, Activity Indicator.
     *      - 1101        Link/Tx           Link, Activity Indicator.
     *      - 1110        Master            Link on Master Indicator.
     *      - 1111        Act               Activity Indicator. Low for link established.
     */
    rtk_api_ret_t rtl_led_groupConfig_set(rtk_led_group_t group, rtk_led_congig_t config);

    /* Function Name:
     *      rtl_led_groupConfig_get
     * Description:
     *      Get Led group congiuration mode
     * Input:
     *      group - LED group.
     * Output:
     *      pConfig - LED configuration.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *       The API can get LED indicated information configuration for each LED group.
     */
    rtk_api_ret_t rtl_led_groupConfig_get(rtk_led_group_t group, rtk_led_congig_t *pConfig);

    /* Function Name:
     *      rtl_led_groupAbility_set
     * Description:
     *      Configure per group Led ability
     * Input:
     *      group    - LED group.
     *      pAbility - LED ability
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      None.
     */

    rtk_api_ret_t rtl_led_groupAbility_set(rtk_led_group_t group, rtk_led_ability_t *pAbility);

    /* Function Name:
     *      rtl_led_groupAbility_get
     * Description:
     *      Get per group Led ability
     * Input:
     *      group    - LED group.
     *      pAbility - LED ability
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      None.
     */

    rtk_api_ret_t rtl_led_groupAbility_get(rtk_led_group_t group, rtk_led_ability_t *pAbility);

    /* Function Name:
     *      rtl_led_serialMode_set
     * Description:
     *      Set Led serial mode active congiuration
     * Input:
     *      active - LED group.
     * Output:
     *      None
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *      The API can set LED serial mode active congiuration.
     */
    rtk_api_ret_t rtl_led_serialMode_set(rtk_led_active_t active);

    /* Function Name:
     *      rtl_led_serialMode_get
     * Description:
     *      Get Led group congiuration mode
     * Input:
     *      group - LED group.
     * Output:
     *      pConfig - LED configuration.
     * Return:
     *      RT_ERR_OK           - OK
     *      RT_ERR_FAILED       - Failed
     *      RT_ERR_SMI          - SMI access error
     *      RT_ERR_INPUT        - Invalid input parameters.
     * Note:
     *       The API can get LED serial mode active configuration.
     */
    rtk_api_ret_t rtl_led_serialMode_get(rtk_led_active_t *pActive);

    /* Function Name:
     *      rtl_led_OutputEnable_set
     * Description:
     *      This API set LED I/O state.
     * Input:
     *      enabled     - LED I/O state
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error parameter
     * Note:
     *      This API set LED I/O state.
     */
    rtk_api_ret_t rtl_led_OutputEnable_set(rtk_enable_t state);

    /* Function Name:
     *      rtl_led_OutputEnable_get
     * Description:
     *      This API get LED I/O state.
     * Input:
     *      None.
     * Output:
     *      pEnabled        - LED I/O state
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error parameter
     * Note:
     *      This API set current LED I/O  state.
     */
    rtk_api_ret_t rtl_led_OutputEnable_get(rtk_enable_t *pState);

    /* Function Name:
     *      rtl_led_serialModePortmask_set
     * Description:
     *      This API configure Serial LED output Group and portmask
     * Input:
     *      output          - output group
     *      pPortmask       - output portmask
     * Output:
     *      None.
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error parameter
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_led_serialModePortmask_set(rtk_led_serialOutput_t output, rtk_portmask_t *pPortmask);

    /* Function Name:
     *      rtl_led_serialModePortmask_get
     * Description:
     *      This API get Serial LED output Group and portmask
     * Input:
     *      None.
     * Output:
     *      pOutput         - output group
     *      pPortmask       - output portmask
     * Return:
     *      RT_ERR_OK              - OK
     *      RT_ERR_FAILED          - Failed
     *      RT_ERR_SMI             - SMI access error
     *      RT_ERR_INPUT           - Error parameter
     * Note:
     *      None.
     */
    rtk_api_ret_t rtl_led_serialModePortmask_get(rtk_led_serialOutput_t *pOutput, rtk_portmask_t *pPortmask);
};

#endif