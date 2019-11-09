/*
 * heli_2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_2".
 *
 * Model version              : 1.64
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Fri Nov 08 22:27:29 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_2.h"
#include "heli_2_private.h"
#include "heli_2_dt.h"

/* Block signals (auto storage) */
B_heli_2_T heli_2_B;

/* Continuous states */
X_heli_2_T heli_2_X;

/* Block states (auto storage) */
DW_heli_2_T heli_2_DW;

/* Real-time model */
RT_MODEL_heli_2_T heli_2_M_;
RT_MODEL_heli_2_T *const heli_2_M = &heli_2_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_2_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_2_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (heli_2_M->Timing.TaskCounters.TID[1] == 0) {
    heli_2_M->Timing.RateInteraction.TID1_2 = (heli_2_M->
      Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_2_M->Timing.perTaskSampleHits[5] =
      heli_2_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_2_M->Timing.TaskCounters.TID[2])++;
  if ((heli_2_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_2_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void heli_2_output0(void)              /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_DeadZoney;
  real_T rtb_Backgain;
  real_T rtb_Frontgain;
  if (rtmIsMajorTimeStep(heli_2_M)) {
    /* set solver stop time */
    if (!(heli_2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_2_M->solverInfo,
                            ((heli_2_M->Timing.clockTickH0 + 1) *
        heli_2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_2_M->solverInfo, ((heli_2_M->Timing.clockTick0
        + 1) * heli_2_M->Timing.stepSize0 + heli_2_M->Timing.clockTickH0 *
        heli_2_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_2_M)) {
    heli_2_M->Timing.t[0] = rtsiGetT(&heli_2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(heli_2_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_2/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(heli_2_DW.HILReadEncoderTimebase_Task, 1,
        &heli_2_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 = heli_2_DW.HILReadEncoderTimebase_Buffer
          [0];
        rtb_HILReadEncoderTimebase_o2 = heli_2_DW.HILReadEncoderTimebase_Buffer
          [1];
        rtb_HILReadEncoderTimebase_o3 = heli_2_DW.HILReadEncoderTimebase_Buffer
          [2];
      }
    }

    /* RateTransition: '<S4>/Rate Transition: x' */
    if (heli_2_M->Timing.RateInteraction.TID1_2) {
      heli_2_B.RateTransitionx = heli_2_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: x' */

    /* DeadZone: '<S4>/Dead Zone: x' */
    if (heli_2_B.RateTransitionx > heli_2_P.DeadZonex_End) {
      rtb_DeadZoney = heli_2_B.RateTransitionx - heli_2_P.DeadZonex_End;
    } else if (heli_2_B.RateTransitionx >= heli_2_P.DeadZonex_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = heli_2_B.RateTransitionx - heli_2_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: x' */

    /* Gain: '<S4>/Joystick_gain_x' incorporates:
     *  Gain: '<S4>/Gain: x'
     */
    heli_2_B.Joystick_gain_x = heli_2_P.Gainx_Gain * rtb_DeadZoney *
      heli_2_P.Joystick_gain_x;

    /* Gain: '<S3>/Pitch: Count to rad' */
    heli_2_B.PitchCounttorad = heli_2_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Sum: '<S3>/Sum1' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    heli_2_B.Sum1 = heli_2_P.p_0 + heli_2_B.PitchCounttorad;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    heli_2_B.Sum1_f = heli_2_B.Sum1 - heli_2_P.p_0;

    /* Constant: '<Root>/Constant2' */
    heli_2_B.Constant2 = heli_2_P.v_s0;

    /* Gain: '<S5>/k_pp' incorporates:
     *  Sum: '<S5>/Sum'
     */
    heli_2_B.k_pp = (heli_2_B.Joystick_gain_x - heli_2_B.Sum1) * heli_2_P.k_pp;
  }

  /* TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  heli_2_B.PitchTransferFcn = 0.0;
  heli_2_B.PitchTransferFcn += heli_2_P.PitchTransferFcn_C *
    heli_2_X.PitchTransferFcn_CSTATE;
  heli_2_B.PitchTransferFcn += heli_2_P.PitchTransferFcn_D *
    heli_2_B.PitchCounttorad;

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/k_pd'
   */
  rtb_Frontgain = heli_2_B.k_pp - heli_2_P.k_pd * heli_2_B.PitchTransferFcn;

  /* Integrator: '<S6>/Integrator' */
  /* Limited  Integrator  */
  if (heli_2_X.Integrator_CSTATE >= heli_2_P.Integrator_UpperSat) {
    heli_2_X.Integrator_CSTATE = heli_2_P.Integrator_UpperSat;
  } else {
    if (heli_2_X.Integrator_CSTATE <= heli_2_P.Integrator_LowerSat) {
      heli_2_X.Integrator_CSTATE = heli_2_P.Integrator_LowerSat;
    }
  }

  if (rtmIsMajorTimeStep(heli_2_M)) {
    /* Gain: '<S3>/Elevation: Count to rad' */
    heli_2_B.ElevationCounttorad = heli_2_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3;

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Constant'
     */
    heli_2_B.Sum = heli_2_P.e_0 + heli_2_B.ElevationCounttorad;

    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<Root>/Constant'
     */
    rtb_DeadZoney = heli_2_P.Constant_Value - heli_2_B.Sum;

    /* Gain: '<S6>/K_ep' */
    heli_2_B.K_ep = heli_2_P.K_ep_Gain * rtb_DeadZoney;
  }

  /* TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  heli_2_B.ElevationTransferFcn = 0.0;
  heli_2_B.ElevationTransferFcn += heli_2_P.ElevationTransferFcn_C *
    heli_2_X.ElevationTransferFcn_CSTATE;
  heli_2_B.ElevationTransferFcn += heli_2_P.ElevationTransferFcn_D *
    heli_2_B.ElevationCounttorad;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<S6>/K_ed'
   *  Integrator: '<S6>/Integrator'
   *  Sum: '<S6>/Sum'
   */
  rtb_Backgain = ((heli_2_X.Integrator_CSTATE + heli_2_B.K_ep) -
                  heli_2_P.K_ed_Gain * heli_2_B.ElevationTransferFcn) +
    heli_2_B.Constant2;
  if (rtmIsMajorTimeStep(heli_2_M)) {
    /* Gain: '<S6>/K_ei' */
    heli_2_B.K_ei = heli_2_P.K_ei_Gain * rtb_DeadZoney;

    /* Gain: '<S3>/Travel: Count to rad' */
    heli_2_B.TravelCounttorad = heli_2_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S3>/Travel: Transfer Fcn' */
  heli_2_B.TravelTransferFcn = 0.0;
  heli_2_B.TravelTransferFcn += heli_2_P.TravelTransferFcn_C *
    heli_2_X.TravelTransferFcn_CSTATE;
  heli_2_B.TravelTransferFcn += heli_2_P.TravelTransferFcn_D *
    heli_2_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(heli_2_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_DeadZoney = (rtb_Backgain - rtb_Frontgain) * heli_2_P.Frontgain_Gain;

  /* Saturate: '<S3>/Front motor: Saturation' */
  if (rtb_DeadZoney > heli_2_P.FrontmotorSaturation_UpperSat) {
    heli_2_B.FrontmotorSaturation = heli_2_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_DeadZoney < heli_2_P.FrontmotorSaturation_LowerSat) {
    heli_2_B.FrontmotorSaturation = heli_2_P.FrontmotorSaturation_LowerSat;
  } else {
    heli_2_B.FrontmotorSaturation = rtb_DeadZoney;
  }

  /* End of Saturate: '<S3>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_DeadZoney = (rtb_Backgain + rtb_Frontgain) * heli_2_P.Backgain_Gain;

  /* Saturate: '<S3>/Back motor: Saturation' */
  if (rtb_DeadZoney > heli_2_P.BackmotorSaturation_UpperSat) {
    heli_2_B.BackmotorSaturation = heli_2_P.BackmotorSaturation_UpperSat;
  } else if (rtb_DeadZoney < heli_2_P.BackmotorSaturation_LowerSat) {
    heli_2_B.BackmotorSaturation = heli_2_P.BackmotorSaturation_LowerSat;
  } else {
    heli_2_B.BackmotorSaturation = rtb_DeadZoney;
  }

  /* End of Saturate: '<S3>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_2_M)) {
    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: heli_2/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_2_DW.HILWriteAnalog_Buffer[0] = heli_2_B.FrontmotorSaturation;
      heli_2_DW.HILWriteAnalog_Buffer[1] = heli_2_B.BackmotorSaturation;
      result = hil_write_analog(heli_2_DW.HILInitialize_Card,
        heli_2_P.HILWriteAnalog_channels, 2, &heli_2_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
      }
    }

    /* RateTransition: '<S4>/Rate Transition: y' */
    if (heli_2_M->Timing.RateInteraction.TID1_2) {
      heli_2_B.RateTransitiony = heli_2_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: y' */

    /* DeadZone: '<S4>/Dead Zone: y' */
    if (heli_2_B.RateTransitiony > heli_2_P.DeadZoney_End) {
      rtb_Frontgain = heli_2_B.RateTransitiony - heli_2_P.DeadZoney_End;
    } else if (heli_2_B.RateTransitiony >= heli_2_P.DeadZoney_Start) {
      rtb_Frontgain = 0.0;
    } else {
      rtb_Frontgain = heli_2_B.RateTransitiony - heli_2_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: y' */

    /* Gain: '<S4>/Joystick_gain_y' incorporates:
     *  Gain: '<S4>/Gain: y'
     */
    heli_2_B.Joystick_gain_y = heli_2_P.Gainy_Gain * rtb_Frontgain *
      heli_2_P.Joystick_gain_y;
  }
}

/* Model update function for TID0 */
void heli_2_update0(void)              /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(heli_2_M)) {
    rt_ertODEUpdateContinuousStates(&heli_2_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_2_M->Timing.clockTick0)) {
    ++heli_2_M->Timing.clockTickH0;
  }

  heli_2_M->Timing.t[0] = rtsiGetSolverStopTime(&heli_2_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_2_M->Timing.clockTick1)) {
    ++heli_2_M->Timing.clockTickH1;
  }

  heli_2_M->Timing.t[1] = heli_2_M->Timing.clockTick1 *
    heli_2_M->Timing.stepSize1 + heli_2_M->Timing.clockTickH1 *
    heli_2_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_2_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  XDot_heli_2_T *_rtXdot;
  _rtXdot = ((XDot_heli_2_T *) heli_2_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_2_P.PitchTransferFcn_A *
    heli_2_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_2_B.PitchCounttorad;

  /* Derivatives for Integrator: '<S6>/Integrator' */
  lsat = (heli_2_X.Integrator_CSTATE <= heli_2_P.Integrator_LowerSat);
  usat = (heli_2_X.Integrator_CSTATE >= heli_2_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (heli_2_B.K_ei > 0.0)) || (usat &&
       (heli_2_B.K_ei < 0.0))) {
    _rtXdot->Integrator_CSTATE = heli_2_B.K_ei;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S6>/Integrator' */

  /* Derivatives for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_2_P.ElevationTransferFcn_A *
    heli_2_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_2_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_2_P.TravelTransferFcn_A *
    heli_2_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_2_B.TravelCounttorad;
}

/* Model output function for TID2 */
void heli_2_output2(void)              /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: heli_2/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_2_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_2_DW.GameController_Controller, &state,
        &new_data);
      if (result == 0) {
        heli_2_B.GameController_o4 = state.x;
        heli_2_B.GameController_o5 = state.y;
      }
    } else {
      heli_2_B.GameController_o4 = 0;
      heli_2_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void heli_2_update2(void)              /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S4>/Rate Transition: x' */
  heli_2_DW.RateTransitionx_Buffer0 = heli_2_B.GameController_o4;

  /* Update for RateTransition: '<S4>/Rate Transition: y' */
  heli_2_DW.RateTransitiony_Buffer0 = heli_2_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_2_M->Timing.clockTick2)) {
    ++heli_2_M->Timing.clockTickH2;
  }

  heli_2_M->Timing.t[2] = heli_2_M->Timing.clockTick2 *
    heli_2_M->Timing.stepSize2 + heli_2_M->Timing.clockTickH2 *
    heli_2_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_2_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_2_output0();
    break;

   case 2 :
    heli_2_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_2_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_2_update0();
    break;

   case 2 :
    heli_2_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_2_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_2_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_2_M, _rt_error_message);
      return;
    }

    if ((heli_2_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (heli_2_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_2_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = heli_2_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_2_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_2_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(heli_2_DW.HILInitialize_Card,
        heli_2_P.HILInitialize_analog_input_chan, 8U,
        &heli_2_DW.HILInitialize_AIMinimums[0],
        &heli_2_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_2_P.HILInitialize_set_analog_output && !is_switching) ||
        (heli_2_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_2_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = heli_2_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_2_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_2_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(heli_2_DW.HILInitialize_Card,
        heli_2_P.HILInitialize_analog_output_cha, 8U,
        &heli_2_DW.HILInitialize_AOMinimums[0],
        &heli_2_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_2_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (heli_2_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_2_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(heli_2_DW.HILInitialize_Card,
        heli_2_P.HILInitialize_analog_output_cha, 8U,
        &heli_2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
        return;
      }
    }

    if (heli_2_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_2_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_2_DW.HILInitialize_Card, heli_2_P.HILInitialize_analog_output_cha,
         8U, &heli_2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_2_P.HILInitialize_set_encoder_param && !is_switching) ||
        (heli_2_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &heli_2_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_2_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(heli_2_DW.HILInitialize_Card,
        heli_2_P.HILInitialize_encoder_channels, 8U, (t_encoder_quadrature_mode *)
        &heli_2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_2_P.HILInitialize_set_encoder_count && !is_switching) ||
        (heli_2_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &heli_2_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_2_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(heli_2_DW.HILInitialize_Card,
        heli_2_P.HILInitialize_encoder_channels, 8U,
        &heli_2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_2_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (heli_2_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_2_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(heli_2_DW.HILInitialize_Card,
        heli_2_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &heli_2_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          heli_2_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &heli_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            heli_2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            heli_2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_2_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            heli_2_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            heli_2_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              heli_2_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_2_DW.HILInitialize_Card,
          &heli_2_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &heli_2_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_2_DW.HILInitialize_Card,
          &heli_2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_2_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_2_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &heli_2_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_2_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &heli_2_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_2_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(heli_2_DW.HILInitialize_Card,
        heli_2_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &heli_2_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_2_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_2_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &heli_2_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_2_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_2_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(heli_2_DW.HILInitialize_Card,
        heli_2_P.HILInitialize_pwm_channels, 8U,
        &heli_2_DW.HILInitialize_POSortedFreqs[0],
        &heli_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
        return;
      }
    }

    if ((heli_2_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (heli_2_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_2_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(heli_2_DW.HILInitialize_Card,
        heli_2_P.HILInitialize_pwm_channels, 8U,
        &heli_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
        return;
      }
    }

    if (heli_2_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_2_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_2_DW.HILInitialize_Card, heli_2_P.HILInitialize_pwm_channels, 8U,
         &heli_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_2/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_2_DW.HILInitialize_Card,
      heli_2_P.HILReadEncoderTimebase_samples_,
      heli_2_P.HILReadEncoderTimebase_channels, 3,
      &heli_2_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_2_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S4>/Rate Transition: x' */
  heli_2_B.RateTransitionx = heli_2_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S4>/Rate Transition: y' */
  heli_2_B.RateTransitiony = heli_2_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: heli_2/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_2_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open(heli_2_P.GameController_ControllerNumber,
        heli_2_P.GameController_BufferSize, deadzone, saturation,
        heli_2_P.GameController_AutoCenter, 0, 1.0,
        &heli_2_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_2_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: x' */
  heli_2_DW.RateTransitionx_Buffer0 = heli_2_P.RateTransitionx_X0;

  /* InitializeConditions for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  heli_2_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  heli_2_X.Integrator_CSTATE = heli_2_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  heli_2_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  heli_2_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: y' */
  heli_2_DW.RateTransitiony_Buffer0 = heli_2_P.RateTransitiony_X0;
}

/* Model terminate function */
void heli_2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_2_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_2_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_2_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (heli_2_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_2_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_2_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (heli_2_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_2_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_2_DW.HILInitialize_Card
                         , heli_2_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , heli_2_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_2_DW.HILInitialize_AOVoltages[0]
                         , &heli_2_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_2_DW.HILInitialize_Card,
            heli_2_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
            &heli_2_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_2_DW.HILInitialize_Card,
            heli_2_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &heli_2_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_2_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_2_DW.HILInitialize_Card);
    hil_close(heli_2_DW.HILInitialize_Card);
    heli_2_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: heli_2/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_2_P.GameController_Enabled) {
      game_controller_close(heli_2_DW.GameController_Controller);
      heli_2_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_2_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_2_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  heli_2_initialize();
}

void MdlTerminate(void)
{
  heli_2_terminate();
}

/* Registration function */
RT_MODEL_heli_2_T *heli_2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  heli_2_P.Integrator_UpperSat = rtInf;
  heli_2_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)heli_2_M, 0,
                sizeof(RT_MODEL_heli_2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_2_M->solverInfo, &heli_2_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_2_M->solverInfo, &rtmGetTPtr(heli_2_M));
    rtsiSetStepSizePtr(&heli_2_M->solverInfo, &heli_2_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_2_M->solverInfo, &heli_2_M->ModelData.derivs);
    rtsiSetContStatesPtr(&heli_2_M->solverInfo, (real_T **)
                         &heli_2_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&heli_2_M->solverInfo,
      &heli_2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_2_M->solverInfo,
      &heli_2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_2_M->solverInfo,
      &heli_2_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_2_M->solverInfo,
      &heli_2_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_2_M->solverInfo, (&rtmGetErrorStatus(heli_2_M)));
    rtsiSetRTModelPtr(&heli_2_M->solverInfo, heli_2_M);
  }

  rtsiSetSimTimeStep(&heli_2_M->solverInfo, MAJOR_TIME_STEP);
  heli_2_M->ModelData.intgData.f[0] = heli_2_M->ModelData.odeF[0];
  heli_2_M->ModelData.contStates = ((real_T *) &heli_2_X);
  rtsiSetSolverData(&heli_2_M->solverInfo, (void *)&heli_2_M->ModelData.intgData);
  rtsiSetSolverName(&heli_2_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_2_M->Timing.sampleTimes = (&heli_2_M->Timing.sampleTimesArray[0]);
    heli_2_M->Timing.offsetTimes = (&heli_2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_2_M->Timing.sampleTimes[0] = (0.0);
    heli_2_M->Timing.sampleTimes[1] = (0.002);
    heli_2_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_2_M->Timing.offsetTimes[0] = (0.0);
    heli_2_M->Timing.offsetTimes[1] = (0.0);
    heli_2_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_2_M, &heli_2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_2_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_2_M->Timing.perTaskSampleHitsArray;
    heli_2_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_2_M, -1);
  heli_2_M->Timing.stepSize0 = 0.002;
  heli_2_M->Timing.stepSize1 = 0.002;
  heli_2_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_2_M->Sizes.checksums[0] = (1779445644U);
  heli_2_M->Sizes.checksums[1] = (484708798U);
  heli_2_M->Sizes.checksums[2] = (1997491257U);
  heli_2_M->Sizes.checksums[3] = (4222332771U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    heli_2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_2_M->extModeInfo,
      &heli_2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_2_M->extModeInfo, heli_2_M->Sizes.checksums);
    rteiSetTPtr(heli_2_M->extModeInfo, rtmGetTPtr(heli_2_M));
  }

  heli_2_M->solverInfoPtr = (&heli_2_M->solverInfo);
  heli_2_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_2_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_2_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_2_M->ModelData.blockIO = ((void *) &heli_2_B);

  {
    heli_2_B.RateTransitionx = 0.0;
    heli_2_B.Joystick_gain_x = 0.0;
    heli_2_B.PitchCounttorad = 0.0;
    heli_2_B.Sum1 = 0.0;
    heli_2_B.Sum1_f = 0.0;
    heli_2_B.Constant2 = 0.0;
    heli_2_B.k_pp = 0.0;
    heli_2_B.PitchTransferFcn = 0.0;
    heli_2_B.ElevationCounttorad = 0.0;
    heli_2_B.Sum = 0.0;
    heli_2_B.K_ep = 0.0;
    heli_2_B.ElevationTransferFcn = 0.0;
    heli_2_B.K_ei = 0.0;
    heli_2_B.TravelCounttorad = 0.0;
    heli_2_B.TravelTransferFcn = 0.0;
    heli_2_B.FrontmotorSaturation = 0.0;
    heli_2_B.BackmotorSaturation = 0.0;
    heli_2_B.RateTransitiony = 0.0;
    heli_2_B.Joystick_gain_y = 0.0;
    heli_2_B.GameController_o4 = 0.0;
    heli_2_B.GameController_o5 = 0.0;
  }

  /* parameters */
  heli_2_M->ModelData.defaultParam = ((real_T *)&heli_2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_2_X;
    heli_2_M->ModelData.contStates = (x);
    (void) memset((void *)&heli_2_X, 0,
                  sizeof(X_heli_2_T));
  }

  /* states (dwork) */
  heli_2_M->ModelData.dwork = ((void *) &heli_2_DW);
  (void) memset((void *)&heli_2_DW, 0,
                sizeof(DW_heli_2_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_2_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_2_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_2_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_2_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_2_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_2_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_2_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_2_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_2_DW.RateTransitionx_Buffer0 = 0.0;
  heli_2_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_2_DW.HILWriteAnalog_Buffer[1] = 0.0;
  heli_2_DW.RateTransitiony_Buffer0 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_2_M->Sizes.numContStates = (4); /* Number of continuous states */
  heli_2_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  heli_2_M->Sizes.numY = (0);          /* Number of model outputs */
  heli_2_M->Sizes.numU = (0);          /* Number of model inputs */
  heli_2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_2_M->Sizes.numSampTimes = (3);  /* Number of sample times */
  heli_2_M->Sizes.numBlocks = (52);    /* Number of blocks */
  heli_2_M->Sizes.numBlockIO = (21);   /* Number of block outputs */
  heli_2_M->Sizes.numBlockPrms = (147);/* Sum of parameter "widths" */
  return heli_2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
