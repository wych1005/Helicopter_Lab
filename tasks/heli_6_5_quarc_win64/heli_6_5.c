/*
 * heli_6_5.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_6_5".
 *
 * Model version              : 1.129
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Sat Nov 09 00:51:08 2019
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_6_5.h"
#include "heli_6_5_private.h"
#include "heli_6_5_dt.h"

t_stream heli_6_5_rtZt_stream = NULL;

/* Block signals (auto storage) */
B_heli_6_5_T heli_6_5_B;

/* Continuous states */
X_heli_6_5_T heli_6_5_X;

/* Block states (auto storage) */
DW_heli_6_5_T heli_6_5_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_heli_6_5_T heli_6_5_PrevZCX;

/* Real-time model */
RT_MODEL_heli_6_5_T heli_6_5_M_;
RT_MODEL_heli_6_5_T *const heli_6_5_M = &heli_6_5_M_;

/* Forward declaration for local functions */
static void heli_6_5_invNxN(const real_T x[25], real_T y[25]);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_6_5_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_6_5_M, 2);
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
  if (heli_6_5_M->Timing.TaskCounters.TID[1] == 0) {
    heli_6_5_M->Timing.RateInteraction.TID1_2 =
      (heli_6_5_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_6_5_M->Timing.perTaskSampleHits[5] =
      heli_6_5_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_6_5_M->Timing.TaskCounters.TID[2])++;
  if ((heli_6_5_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_6_5_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_6_5_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void heli_6_5_invNxN(const real_T x[25], real_T y[25])
{
  int8_T p[5];
  real_T A[25];
  int8_T ipiv[5];
  int32_T b_j;
  real_T smax;
  real_T s;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kAcol;
  int32_T c_i;
  for (b_j = 0; b_j < 25; b_j++) {
    y[b_j] = 0.0;
    A[b_j] = x[b_j];
  }

  for (b_j = 0; b_j < 5; b_j++) {
    ipiv[b_j] = (int8_T)(1 + b_j);
  }

  for (b_j = 0; b_j < 4; b_j++) {
    jBcol = b_j * 6;
    iy = 0;
    kAcol = jBcol;
    smax = fabs(A[jBcol]);
    for (c_i = 2; c_i <= 5 - b_j; c_i++) {
      kAcol++;
      s = fabs(A[kAcol]);
      if (s > smax) {
        iy = c_i - 1;
        smax = s;
      }
    }

    if (A[jBcol + iy] != 0.0) {
      if (iy != 0) {
        ipiv[b_j] = (int8_T)((b_j + iy) + 1);
        kAcol = b_j;
        iy += b_j;
        for (c_i = 0; c_i < 5; c_i++) {
          smax = A[kAcol];
          A[kAcol] = A[iy];
          A[iy] = smax;
          kAcol += 5;
          iy += 5;
        }
      }

      iy = (jBcol - b_j) + 5;
      for (kAcol = jBcol + 1; kAcol + 1 <= iy; kAcol++) {
        A[kAcol] /= A[jBcol];
      }
    }

    iy = jBcol;
    kAcol = jBcol + 5;
    for (c_i = 1; c_i <= 4 - b_j; c_i++) {
      smax = A[kAcol];
      if (A[kAcol] != 0.0) {
        c_ix = jBcol + 1;
        d = (iy - b_j) + 10;
        for (ijA = 6 + iy; ijA + 1 <= d; ijA++) {
          A[ijA] += A[c_ix] * -smax;
          c_ix++;
        }
      }

      kAcol += 5;
      iy += 5;
    }
  }

  for (b_j = 0; b_j < 5; b_j++) {
    p[b_j] = (int8_T)(1 + b_j);
  }

  if (ipiv[0] > 1) {
    jBcol = p[ipiv[0] - 1];
    p[ipiv[0] - 1] = p[0];
    p[0] = (int8_T)jBcol;
  }

  if (ipiv[1] > 2) {
    jBcol = p[ipiv[1] - 1];
    p[ipiv[1] - 1] = p[1];
    p[1] = (int8_T)jBcol;
  }

  if (ipiv[2] > 3) {
    jBcol = p[ipiv[2] - 1];
    p[ipiv[2] - 1] = p[2];
    p[2] = (int8_T)jBcol;
  }

  if (ipiv[3] > 4) {
    jBcol = p[ipiv[3] - 1];
    p[ipiv[3] - 1] = p[3];
    p[3] = (int8_T)jBcol;
  }

  for (b_j = 0; b_j < 5; b_j++) {
    jBcol = p[b_j] - 1;
    y[b_j + 5 * (p[b_j] - 1)] = 1.0;
    for (iy = b_j; iy + 1 < 6; iy++) {
      if (y[5 * jBcol + iy] != 0.0) {
        for (kAcol = iy + 1; kAcol + 1 < 6; kAcol++) {
          y[kAcol + 5 * jBcol] -= y[5 * jBcol + iy] * A[5 * iy + kAcol];
        }
      }
    }
  }

  for (b_j = 0; b_j < 5; b_j++) {
    jBcol = 5 * b_j;
    for (iy = 4; iy >= 0; iy += -1) {
      kAcol = 5 * iy;
      if (y[iy + jBcol] != 0.0) {
        y[iy + jBcol] /= A[iy + kAcol];
        for (c_i = 0; c_i + 1 <= iy; c_i++) {
          y[c_i + jBcol] -= y[iy + jBcol] * A[c_i + kAcol];
        }
      }
    }
  }
}

/* Model output function for TID0 */
void heli_6_5_output0(void)            /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_FrontmotorSaturation;
  real_T rtb_BackmotorSaturation;
  t_stream_ptr rtb_StreamCall1_o1;
  t_stream_ptr rtb_StreamFormattedWrite_o1;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  int32_T rtb_StreamRead1_o5;
  real_T Kk[30];
  real_T xk_hat[6];
  real_T Pk_hat[36];
  int8_T I[36];
  int32_T k;
  int8_T b_I[36];
  real_T rtb_Switch[10];
  real_T rtb_Gain2[3];
  real_T rtb_K[2];
  int32_T i;
  real_T tmp[25];
  real_T tmp_0[25];
  real_T I_0[36];
  real_T tmp_1[9];
  real_T tmp_2[3];
  real_T tmp_3[5];
  real_T I_1[6];
  real_T Kk_0[6];
  real_T b_I_0[36];
  real_T tmp_4;
  real_T Kk_1[30];
  real_T Kk_2[36];
  int32_T i_0;
  if (rtmIsMajorTimeStep(heli_6_5_M)) {
    /* set solver stop time */
    if (!(heli_6_5_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_6_5_M->solverInfo,
                            ((heli_6_5_M->Timing.clockTickH0 + 1) *
        heli_6_5_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_6_5_M->solverInfo,
                            ((heli_6_5_M->Timing.clockTick0 + 1) *
        heli_6_5_M->Timing.stepSize0 + heli_6_5_M->Timing.clockTickH0 *
        heli_6_5_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_6_5_M)) {
    heli_6_5_M->Timing.t[0] = rtsiGetT(&heli_6_5_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(heli_6_5_DW.Subsystem6_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(heli_6_5_DW.TriggeredSubsystem_SubsysRanBC);
  if (rtmIsMajorTimeStep(heli_6_5_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_6_5/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(heli_6_5_DW.HILReadEncoderTimebase_Task, 1,
        &heli_6_5_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_6_5_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_6_5_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_FrontmotorSaturation = heli_6_5_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* UnitDelay: '<Root>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      heli_6_5_B.UnitDelay[i] = heli_6_5_DW.UnitDelay_DSTATE[i];
    }

    /* End of UnitDelay: '<Root>/Unit Delay' */

    /* RateTransition: '<S5>/Rate Transition: x' */
    if (heli_6_5_M->Timing.RateInteraction.TID1_2) {
      heli_6_5_B.RateTransitionx = heli_6_5_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S5>/Rate Transition: x' */

    /* DeadZone: '<S5>/Dead Zone: x' */
    if (heli_6_5_B.RateTransitionx > heli_6_5_P.DeadZonex_End) {
      rtb_BackmotorSaturation = heli_6_5_B.RateTransitionx -
        heli_6_5_P.DeadZonex_End;
    } else if (heli_6_5_B.RateTransitionx >= heli_6_5_P.DeadZonex_Start) {
      rtb_BackmotorSaturation = 0.0;
    } else {
      rtb_BackmotorSaturation = heli_6_5_B.RateTransitionx -
        heli_6_5_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S5>/Dead Zone: x' */

    /* Gain: '<S5>/Joystick_gain_x' incorporates:
     *  Gain: '<S5>/Gain: x'
     */
    heli_6_5_B.Joystick_gain_x = heli_6_5_P.Gainx_Gain * rtb_BackmotorSaturation
      * heli_6_5_P.Joystick_gain_x;

    /* RateTransition: '<S5>/Rate Transition: y' */
    if (heli_6_5_M->Timing.RateInteraction.TID1_2) {
      heli_6_5_B.RateTransitiony = heli_6_5_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S5>/Rate Transition: y' */

    /* DeadZone: '<S5>/Dead Zone: y' */
    if (heli_6_5_B.RateTransitiony > heli_6_5_P.DeadZoney_End) {
      rtb_BackmotorSaturation = heli_6_5_B.RateTransitiony -
        heli_6_5_P.DeadZoney_End;
    } else if (heli_6_5_B.RateTransitiony >= heli_6_5_P.DeadZoney_Start) {
      rtb_BackmotorSaturation = 0.0;
    } else {
      rtb_BackmotorSaturation = heli_6_5_B.RateTransitiony -
        heli_6_5_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S5>/Dead Zone: y' */

    /* Gain: '<S5>/Joystick_gain_y' incorporates:
     *  Gain: '<S5>/Gain: y'
     */
    heli_6_5_B.Joystick_gain_y = heli_6_5_P.Gainy_Gain * rtb_BackmotorSaturation
      * heli_6_5_P.Joystick_gain_y;

    /* S-Function (stream_call_block): '<S4>/Stream Call1' */

    /* S-Function Block: heli_6_5/IMU/Stream Call1 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_6_5_P.Constant_Value != 0);
      rtb_StreamCall1_o1 = NULL;
      switch (heli_6_5_DW.StreamCall1_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) heli_6_5_P.StringConstant_Value, 255) ==
                255) {
              rtmSetErrorStatus(heli_6_5_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *) heli_6_5_P.StringConstant_Value,
                true, heli_6_5_P.StreamCall1_SendBufferSize,
                heli_6_5_P.StreamCall1_ReceiveBufferSize,
                &heli_6_5_DW.StreamCall1_Stream);
              if (result == 0) {
                heli_6_5_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_6_5_DW.StreamCall1_Stream,
                                      (t_stream_byte_order)
                                      heli_6_5_P.StreamCall1_Endian);
                rtb_StreamCall1_o1 = &heli_6_5_DW.StreamCall1_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_6_5_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTING;
                result = 0;
              }
            }
          }
          break;
        }

       case STREAM_CALL_STATE_CONNECTING:
        {
          if (!close_flag) {
            const t_timeout timeout = { 0, 0, false };/* zero seconds */

            result = stream_poll(heli_6_5_DW.StreamCall1_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_6_5_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_6_5_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_6_5_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_6_5_DW.StreamCall1_Stream;
              result = 0;
              break;
            } else if (result == 0) {
              break;
            }
          }

          /* Fall through deliberately */
        }

       case STREAM_CALL_STATE_CONNECTED:
        {
          rtb_StreamCall1_o1 = &heli_6_5_DW.StreamCall1_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close(heli_6_5_DW.StreamCall1_Stream);
          if (close_result == 0) {
            heli_6_5_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
            heli_6_5_DW.StreamCall1_Stream = NULL;
            rtb_StreamCall1_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      heli_6_5_B.StreamCall1_o2 = heli_6_5_DW.StreamCall1_State;
      rtb_StreamCall1_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_write_block): '<S4>/Stream Formatted Write' */
    {
      t_error result;
      if (rtb_StreamCall1_o1 != NULL) {
        result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
          heli_6_5_P.StreamFormattedWrite_MaxUnits, &rtb_StreamFormattedWrite_o2,
          "%c\n"
          , (char) heli_6_5_P.Constant1_Value
          );
        if (result > 0) {
          result = stream_flush(*rtb_StreamCall1_o1);
        }

        if (result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      }

      rtb_StreamFormattedWrite_o1 = rtb_StreamCall1_o1;
    }

    /* S-Function (stream_read_block): '<S4>/Stream Read1' */
    /* S-Function Block: heli_6_5/IMU/Stream Read1 (stream_read_block) */
    {
      t_error result;
      memset(&rtb_StreamRead1_o2[0], 0, 10 * sizeof(real32_T));
      if (rtb_StreamFormattedWrite_o1 != NULL) {
        result = stream_receive_unit_array(*rtb_StreamFormattedWrite_o1,
          &rtb_StreamRead1_o2[0], sizeof(real32_T), 10);
        heli_6_5_B.StreamRead1_o3 = (result > 0);
        if (result > 0 || result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      } else {
        heli_6_5_B.StreamRead1_o3 = false;
        result = 0;
      }

      rtb_StreamRead1_o5 = (int32_T) result;
    }

    /* Outputs for Triggered SubSystem: '<Root>/Subsystem6' incorporates:
     *  TriggerPort: '<S9>/Trigger'
     */
    if (rtmIsMajorTimeStep(heli_6_5_M)) {
      if (heli_6_5_B.StreamRead1_o3 && (heli_6_5_PrevZCX.Subsystem6_Trig_ZCE !=
           POS_ZCSIG)) {
        /* Gain: '<S12>/K' incorporates:
         *  SignalConversion: '<S12>/TmpSignal ConversionAtKInport1'
         */
        for (i = 0; i < 2; i++) {
          rtb_K[i] = heli_6_5_P.K[i + 4] * heli_6_5_B.UnitDelay[3] +
            (heli_6_5_P.K[i + 2] * heli_6_5_B.UnitDelay[1] + heli_6_5_P.K[i] *
             heli_6_5_B.UnitDelay[0]);
        }

        /* End of Gain: '<S12>/K' */

        /* Sum: '<S9>/Sum' incorporates:
         *  Gain: '<S11>/Gain'
         *  SignalConversion: '<S11>/TmpSignal ConversionAtGainInport1'
         */
        heli_6_5_B.Sum_i = (heli_6_5_P.F[0] * heli_6_5_B.Joystick_gain_x +
                            heli_6_5_P.F[2] * heli_6_5_B.Joystick_gain_y) -
          rtb_K[0];

        /* Sum: '<S9>/Sum1' incorporates:
         *  Gain: '<S11>/Gain'
         *  SignalConversion: '<S11>/TmpSignal ConversionAtGainInport1'
         */
        heli_6_5_B.Sum1_h = (heli_6_5_P.F[1] * heli_6_5_B.Joystick_gain_x +
                             heli_6_5_P.F[3] * heli_6_5_B.Joystick_gain_y) -
          rtb_K[1];

        /* Sum: '<S9>/Sum2' incorporates:
         *  Constant: '<S9>/Constant1'
         */
        heli_6_5_B.Sum2 = heli_6_5_B.Sum_i + heli_6_5_P.v_s0;
        heli_6_5_DW.Subsystem6_SubsysRanBC = 4;
      }

      heli_6_5_PrevZCX.Subsystem6_Trig_ZCE = heli_6_5_B.StreamRead1_o3;
    }

    /* End of Outputs for SubSystem: '<Root>/Subsystem6' */

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant2'
     *  DataTypeConversion: '<S4>/Data Type Conversion'
     */
    for (i = 0; i < 10; i++) {
      if (heli_6_5_B.StreamRead1_o3) {
        rtb_Switch[i] = rtb_StreamRead1_o2[i];
      } else {
        rtb_Switch[i] = heli_6_5_P.Constant2_Value;
      }
    }

    /* End of Switch: '<S4>/Switch' */

    /* Gain: '<S4>/Gain2' */
    /* MATLAB Function 'Gyro vector to [pitch rate, elevation rate, travle rate]': '<S2>:1' */
    /* '<S2>:1:3' */
    /* '<S2>:1:4' */
    /*      psi = euler_angles(3); */
    /* '<S2>:1:8' */
    /* '<S2>:1:11' */
    for (i = 0; i < 3; i++) {
      rtb_Gain2[i] = heli_6_5_P.Gain2_Gain[i + 6] * rtb_Switch[2] +
        (heli_6_5_P.Gain2_Gain[i + 3] * rtb_Switch[1] + heli_6_5_P.Gain2_Gain[i]
         * rtb_Switch[0]);
    }

    /* End of Gain: '<S4>/Gain2' */

    /* Sum: '<S6>/Sum3' incorporates:
     *  Math: '<S6>/a_y^2'
     *  Math: '<S6>/a_z^2'
     */
    rtb_BackmotorSaturation = rtb_Gain2[1] * rtb_Gain2[1] + rtb_Gain2[2] *
      rtb_Gain2[2];

    /* Sqrt: '<S6>/Sqrt' */
    rtb_BackmotorSaturation = sqrt(rtb_BackmotorSaturation);

    /* Outputs for Triggered SubSystem: '<Root>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S10>/Trigger'
     */
    if (rtmIsMajorTimeStep(heli_6_5_M)) {
      if (heli_6_5_B.StreamRead1_o3 &&
          (heli_6_5_PrevZCX.TriggeredSubsystem_Trig_ZCE != POS_ZCSIG)) {
        /* UnitDelay: '<S10>/Unit Delay1' */
        memcpy(&heli_6_5_B.UnitDelay1[0], &heli_6_5_DW.UnitDelay1_DSTATE[0], 36U
               * sizeof(real_T));

        /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
         *  Constant: '<S10>/Constant'
         *  Constant: '<S10>/Constant2'
         *  Constant: '<S10>/Constant3'
         *  Constant: '<S10>/Constant4'
         *  SignalConversion: '<S13>/TmpSignal ConversionAt SFunction Inport1'
         *  SignalConversion: '<S13>/TmpSignal ConversionAt SFunction Inport3'
         */
        /* MATLAB Function 'Triggered Subsystem/MATLAB Function': '<S13>:1' */
        /* '<S13>:1:2' */
        for (i = 0; i < 5; i++) {
          for (i_0 = 0; i_0 < 6; i_0++) {
            Kk_1[i + 5 * i_0] = 0.0;
            for (k = 0; k < 6; k++) {
              Kk_1[i + 5 * i_0] += heli_6_5_P.C_d[5 * k + i] *
                heli_6_5_B.UnitDelay1[6 * i_0 + k];
            }
          }
        }

        for (i = 0; i < 5; i++) {
          for (i_0 = 0; i_0 < 5; i_0++) {
            tmp_4 = 0.0;
            for (k = 0; k < 6; k++) {
              tmp_4 += Kk_1[5 * k + i] * heli_6_5_P.C_d[5 * k + i_0];
            }

            tmp[i + 5 * i_0] = heli_6_5_P.R_d[5 * i_0 + i] + tmp_4;
          }
        }

        heli_6_5_invNxN(tmp, tmp_0);
        for (i = 0; i < 6; i++) {
          for (i_0 = 0; i_0 < 5; i_0++) {
            Kk_1[i + 6 * i_0] = 0.0;
            for (k = 0; k < 6; k++) {
              Kk_1[i + 6 * i_0] += heli_6_5_B.UnitDelay1[6 * k + i] *
                heli_6_5_P.C_d[5 * k + i_0];
            }
          }
        }

        for (i = 0; i < 6; i++) {
          for (i_0 = 0; i_0 < 5; i_0++) {
            Kk[i + 6 * i_0] = 0.0;
            for (k = 0; k < 5; k++) {
              Kk[i + 6 * i_0] += Kk_1[6 * k + i] * tmp_0[5 * i_0 + k];
            }
          }
        }

        if (!heli_6_5_B.StreamRead1_o3) {
          /* '<S13>:1:3' */
          /* '<S13>:1:4' */
          for (i = 0; i < 6; i++) {
            xk_hat[i] = heli_6_5_B.UnitDelay[i];
          }

          /* '<S13>:1:5' */
          memcpy(&Pk_hat[0], &heli_6_5_B.UnitDelay1[0], 36U * sizeof(real_T));
        } else {
          /* '<S13>:1:7' */
          for (i = 0; i < 36; i++) {
            I[i] = 0;
          }

          for (k = 0; k < 6; k++) {
            I[k + 6 * k] = 1;
          }

          for (i = 0; i < 6; i++) {
            for (i_0 = 0; i_0 < 6; i_0++) {
              tmp_4 = 0.0;
              for (k = 0; k < 5; k++) {
                tmp_4 += Kk[6 * k + i] * heli_6_5_P.C_d[5 * i_0 + k];
              }

              I_0[i + 6 * i_0] = (real_T)I[6 * i_0 + i] - tmp_4;
            }
          }

          /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' incorporates:
           *  Constant: '<S10>/Constant3'
           *  SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport2'
           */
          tmp_1[0] = 1.0;
          tmp_1[3] = sin(heli_6_5_B.UnitDelay[2]) * tan(heli_6_5_B.UnitDelay[4]);
          tmp_1[6] = cos(heli_6_5_B.UnitDelay[2]) * tan(heli_6_5_B.UnitDelay[4]);
          tmp_1[1] = 0.0;
          tmp_1[4] = cos(heli_6_5_B.UnitDelay[2]);
          tmp_1[7] = -sin(heli_6_5_B.UnitDelay[2]);
          tmp_1[2] = 0.0;
          tmp_1[5] = sin(heli_6_5_B.UnitDelay[2]) / cos(heli_6_5_B.UnitDelay[4]);
          tmp_1[8] = cos(heli_6_5_B.UnitDelay[2]) / cos(heli_6_5_B.UnitDelay[4]);

          /* Gain: '<S4>/Gain1' incorporates:
           *  MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]'
           */
          for (i = 0; i < 3; i++) {
            tmp_2[i] = heli_6_5_P.Gain1_Gain[i + 6] * rtb_Switch[5] +
              (heli_6_5_P.Gain1_Gain[i + 3] * rtb_Switch[4] +
               heli_6_5_P.Gain1_Gain[i] * rtb_Switch[3]);
          }

          /* End of Gain: '<S4>/Gain1' */
          for (i = 0; i < 3; i++) {
            /* SignalConversion: '<S13>/TmpSignal ConversionAt SFunction Inport3' incorporates:
             *  MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]'
             */
            tmp_3[i] = tmp_1[i + 6] * tmp_2[2] + (tmp_1[i + 3] * tmp_2[1] +
              tmp_1[i] * tmp_2[0]);
          }

          /* SignalConversion: '<S13>/TmpSignal ConversionAt SFunction Inport3' incorporates:
           *  Product: '<S6>/tg_e'
           *  Product: '<S6>/tg_p'
           *  Trigonometry: '<S6>/ee'
           *  Trigonometry: '<S6>/pp'
           */
          tmp_3[3] = atan(rtb_Gain2[1] / rtb_Gain2[2]);
          tmp_3[4] = atan(rtb_Gain2[0] / rtb_BackmotorSaturation);
          for (i = 0; i < 6; i++) {
            I_1[i] = 0.0;
            for (i_0 = 0; i_0 < 6; i_0++) {
              I_1[i] += I_0[6 * i_0 + i] * heli_6_5_B.UnitDelay[i_0];
            }

            Kk_0[i] = 0.0;
            for (i_0 = 0; i_0 < 5; i_0++) {
              Kk_0[i] += Kk[6 * i_0 + i] * tmp_3[i_0];
            }

            xk_hat[i] = I_1[i] + Kk_0[i];
          }

          /* '<S13>:1:8' */
          for (i = 0; i < 36; i++) {
            I[i] = 0;
          }

          for (k = 0; k < 6; k++) {
            I[k + 6 * k] = 1;
          }

          for (i = 0; i < 36; i++) {
            b_I[i] = 0;
          }

          for (k = 0; k < 6; k++) {
            b_I[k + 6 * k] = 1;
            for (i = 0; i < 6; i++) {
              tmp_4 = 0.0;
              for (i_0 = 0; i_0 < 5; i_0++) {
                tmp_4 += Kk[6 * i_0 + k] * heli_6_5_P.C_d[5 * i + i_0];
              }

              I_0[k + 6 * i] = (real_T)I[6 * i + k] - tmp_4;
            }
          }

          for (i = 0; i < 6; i++) {
            for (i_0 = 0; i_0 < 6; i_0++) {
              Pk_hat[i + 6 * i_0] = 0.0;
              for (k = 0; k < 6; k++) {
                Pk_hat[i + 6 * i_0] += I_0[6 * k + i] * heli_6_5_B.UnitDelay1[6 *
                  i_0 + k];
              }

              tmp_4 = 0.0;
              for (k = 0; k < 5; k++) {
                tmp_4 += Kk[6 * k + i_0] * heli_6_5_P.C_d[5 * i + k];
              }

              b_I_0[i + 6 * i_0] = (real_T)b_I[6 * i + i_0] - tmp_4;
            }

            for (i_0 = 0; i_0 < 5; i_0++) {
              Kk_1[i + 6 * i_0] = 0.0;
              for (k = 0; k < 5; k++) {
                Kk_1[i + 6 * i_0] += Kk[6 * k + i] * heli_6_5_P.R_d[5 * i_0 + k];
              }
            }
          }

          for (i = 0; i < 6; i++) {
            for (i_0 = 0; i_0 < 6; i_0++) {
              I_0[i + 6 * i_0] = 0.0;
              for (k = 0; k < 6; k++) {
                I_0[i + 6 * i_0] += Pk_hat[6 * k + i] * b_I_0[6 * i_0 + k];
              }

              Kk_2[i + 6 * i_0] = 0.0;
              for (k = 0; k < 5; k++) {
                Kk_2[i + 6 * i_0] += Kk_1[6 * k + i] * Kk[6 * k + i_0];
              }
            }
          }

          for (i = 0; i < 6; i++) {
            for (i_0 = 0; i_0 < 6; i_0++) {
              Pk_hat[i_0 + 6 * i] = I_0[6 * i + i_0] + Kk_2[6 * i + i_0];
            }
          }
        }

        /* '<S13>:1:11' */
        /* '<S13>:1:12' */
        for (i = 0; i < 6; i++) {
          I_1[i] = 0.0;
          Kk_0[i] = 0.0;
          Kk_0[i] += heli_6_5_P.B_d[i] * heli_6_5_B.Sum_i;
          Kk_0[i] += heli_6_5_P.B_d[i + 6] * heli_6_5_B.Sum1_h;
          for (i_0 = 0; i_0 < 6; i_0++) {
            I_1[i] += heli_6_5_P.A_d[6 * i_0 + i] * xk_hat[i_0];
            I_0[i + 6 * i_0] = 0.0;
            for (k = 0; k < 6; k++) {
              I_0[i + 6 * i_0] += heli_6_5_P.A_d[6 * k + i] * Pk_hat[6 * i_0 + k];
            }
          }

          heli_6_5_B.xk1[i] = I_1[i] + Kk_0[i];
        }

        /* Update for UnitDelay: '<S10>/Unit Delay1' incorporates:
         *  Constant: '<S10>/Constant'
         *  Constant: '<S10>/Constant1'
         *  MATLAB Function: '<S10>/MATLAB Function'
         */
        for (i = 0; i < 6; i++) {
          for (i_0 = 0; i_0 < 6; i_0++) {
            tmp_4 = 0.0;
            for (k = 0; k < 6; k++) {
              tmp_4 += I_0[6 * k + i] * heli_6_5_P.A_d[6 * k + i_0];
            }

            heli_6_5_DW.UnitDelay1_DSTATE[i + 6 * i_0] = heli_6_5_P.Q_d[6 * i_0
              + i] + tmp_4;
          }
        }

        /* End of Update for UnitDelay: '<S10>/Unit Delay1' */
        heli_6_5_DW.TriggeredSubsystem_SubsysRanBC = 4;
      }

      heli_6_5_PrevZCX.TriggeredSubsystem_Trig_ZCE = heli_6_5_B.StreamRead1_o3;
    }

    /* End of Outputs for SubSystem: '<Root>/Triggered Subsystem' */

    /* Product: '<S8>/Matrix Multiply' incorporates:
     *  Constant: '<S8>/Constant'
     *  Gain: '<S8>/Gain'
     */
    for (i = 0; i < 6; i++) {
      for (i_0 = 0; i_0 < 6; i_0++) {
        I_0[i + 6 * i_0] = 0.0;
        for (k = 0; k < 6; k++) {
          I_0[i + 6 * i_0] += heli_6_5_B.UnitDelay1[6 * k + i] * heli_6_5_P.M[6 *
            i_0 + k];
        }
      }
    }

    /* End of Product: '<S8>/Matrix Multiply' */

    /* Gain: '<S8>/Gain' */
    for (i = 0; i < 6; i++) {
      heli_6_5_B.Gain[i] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        heli_6_5_B.Gain[i] += I_0[6 * i_0 + i] * heli_6_5_P.v[i_0];
      }
    }

    /* Gain: '<S3>/Travel: Count to rad' */
    heli_6_5_B.TravelCounttorad = heli_6_5_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S3>/Pitch: Count to rad' */
    heli_6_5_B.PitchCounttorad = heli_6_5_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Sum: '<S3>/Sum1' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    heli_6_5_B.Sum1 = heli_6_5_B.PitchCounttorad - heli_6_5_P.Constant1_Value_o;
  }

  /* TransferFcn: '<S3>/Travel: Transfer Fcn' */
  heli_6_5_B.TravelTransferFcn = 0.0;
  heli_6_5_B.TravelTransferFcn += heli_6_5_P.TravelTransferFcn_C *
    heli_6_5_X.TravelTransferFcn_CSTATE;
  heli_6_5_B.TravelTransferFcn += heli_6_5_P.TravelTransferFcn_D *
    heli_6_5_B.TravelCounttorad;

  /* TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  heli_6_5_B.PitchTransferFcn = 0.0;
  heli_6_5_B.PitchTransferFcn += heli_6_5_P.PitchTransferFcn_C *
    heli_6_5_X.PitchTransferFcn_CSTATE;
  heli_6_5_B.PitchTransferFcn += heli_6_5_P.PitchTransferFcn_D *
    heli_6_5_B.PitchCounttorad;
  if (rtmIsMajorTimeStep(heli_6_5_M)) {
    /* Gain: '<S3>/Elevation: Count to rad' */
    heli_6_5_B.ElevationCounttorad = heli_6_5_P.ElevationCounttorad_Gain *
      rtb_FrontmotorSaturation;

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Constant'
     */
    heli_6_5_B.Sum = heli_6_5_B.ElevationCounttorad -
      heli_6_5_P.Constant_Value_b;
  }

  /* TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  heli_6_5_B.ElevationTransferFcn = 0.0;
  heli_6_5_B.ElevationTransferFcn += heli_6_5_P.ElevationTransferFcn_C *
    heli_6_5_X.ElevationTransferFcn_CSTATE;
  heli_6_5_B.ElevationTransferFcn += heli_6_5_P.ElevationTransferFcn_D *
    heli_6_5_B.ElevationCounttorad;

  /* Sum: '<Root>/Sum3' */
  heli_6_5_B.Sum3[0] = heli_6_5_B.TravelCounttorad - heli_6_5_B.UnitDelay[4];
  heli_6_5_B.Sum3[1] = heli_6_5_B.TravelTransferFcn - heli_6_5_B.UnitDelay[5];
  heli_6_5_B.Sum3[2] = heli_6_5_B.Sum1 - heli_6_5_B.UnitDelay[0];
  heli_6_5_B.Sum3[3] = heli_6_5_B.PitchTransferFcn - heli_6_5_B.UnitDelay[1];
  heli_6_5_B.Sum3[4] = heli_6_5_B.Sum - heli_6_5_B.UnitDelay[2];
  heli_6_5_B.Sum3[5] = heli_6_5_B.ElevationTransferFcn - heli_6_5_B.UnitDelay[3];
  if (rtmIsMajorTimeStep(heli_6_5_M)) {
    /* Gain: '<S1>/Back gain' incorporates:
     *  Sum: '<S1>/Subtract'
     */
    rtb_BackmotorSaturation = (heli_6_5_B.Sum2 + heli_6_5_B.Sum1_h) *
      heli_6_5_P.Backgain_Gain;

    /* Gain: '<S1>/Front gain' incorporates:
     *  Sum: '<S1>/Add'
     */
    rtb_FrontmotorSaturation = (heli_6_5_B.Sum2 - heli_6_5_B.Sum1_h) *
      heli_6_5_P.Frontgain_Gain;

    /* Saturate: '<S3>/Front motor: Saturation' */
    if (rtb_FrontmotorSaturation > heli_6_5_P.FrontmotorSaturation_UpperSat) {
      rtb_FrontmotorSaturation = heli_6_5_P.FrontmotorSaturation_UpperSat;
    } else {
      if (rtb_FrontmotorSaturation < heli_6_5_P.FrontmotorSaturation_LowerSat) {
        rtb_FrontmotorSaturation = heli_6_5_P.FrontmotorSaturation_LowerSat;
      }
    }

    /* End of Saturate: '<S3>/Front motor: Saturation' */

    /* Saturate: '<S3>/Back motor: Saturation' */
    if (rtb_BackmotorSaturation > heli_6_5_P.BackmotorSaturation_UpperSat) {
      rtb_BackmotorSaturation = heli_6_5_P.BackmotorSaturation_UpperSat;
    } else {
      if (rtb_BackmotorSaturation < heli_6_5_P.BackmotorSaturation_LowerSat) {
        rtb_BackmotorSaturation = heli_6_5_P.BackmotorSaturation_LowerSat;
      }
    }

    /* End of Saturate: '<S3>/Back motor: Saturation' */

    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: heli_6_5/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_6_5_DW.HILWriteAnalog_Buffer[0] = rtb_FrontmotorSaturation;
      heli_6_5_DW.HILWriteAnalog_Buffer[1] = rtb_BackmotorSaturation;
      result = hil_write_analog(heli_6_5_DW.HILInitialize_Card,
        heli_6_5_P.HILWriteAnalog_channels, 2,
        &heli_6_5_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
      }
    }

    /* S-Function (stop_with_error_block): '<S4>/Stop with Call Error' */

    /* S-Function Block: heli_6_5/IMU/Stop with Call Error (stop_with_error_block) */
    {
      if (rtb_StreamCall1_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stop_with_error_block): '<S4>/Stop with Read Error' */

    /* S-Function Block: heli_6_5/IMU/Stop with Read Error (stop_with_error_block) */
    {
      if (rtb_StreamRead1_o5 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model update function for TID0 */
void heli_6_5_update0(void)            /* Sample time: [0.0s, 0.0s] */
{
  int32_T i;
  if (rtmIsMajorTimeStep(heli_6_5_M)) {
    /* Update for UnitDelay: '<Root>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      heli_6_5_DW.UnitDelay_DSTATE[i] = heli_6_5_B.xk1[i];
    }

    /* End of Update for UnitDelay: '<Root>/Unit Delay' */
  }

  if (rtmIsMajorTimeStep(heli_6_5_M)) {
    rt_ertODEUpdateContinuousStates(&heli_6_5_M->solverInfo);
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
  if (!(++heli_6_5_M->Timing.clockTick0)) {
    ++heli_6_5_M->Timing.clockTickH0;
  }

  heli_6_5_M->Timing.t[0] = rtsiGetSolverStopTime(&heli_6_5_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_6_5_M->Timing.clockTick1)) {
    ++heli_6_5_M->Timing.clockTickH1;
  }

  heli_6_5_M->Timing.t[1] = heli_6_5_M->Timing.clockTick1 *
    heli_6_5_M->Timing.stepSize1 + heli_6_5_M->Timing.clockTickH1 *
    heli_6_5_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_6_5_derivatives(void)
{
  XDot_heli_6_5_T *_rtXdot;
  _rtXdot = ((XDot_heli_6_5_T *) heli_6_5_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_6_5_P.TravelTransferFcn_A *
    heli_6_5_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_6_5_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_6_5_P.PitchTransferFcn_A *
    heli_6_5_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_6_5_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_6_5_P.ElevationTransferFcn_A *
    heli_6_5_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_6_5_B.ElevationCounttorad;
}

/* Model output function for TID2 */
void heli_6_5_output2(void)            /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S5>/Game Controller' */

  /* S-Function Block: heli_6_5/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_6_5_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_6_5_DW.GameController_Controller,
        &state, &new_data);
      if (result == 0) {
        heli_6_5_B.GameController_o4 = state.x;
        heli_6_5_B.GameController_o5 = state.y;
      }
    } else {
      heli_6_5_B.GameController_o4 = 0;
      heli_6_5_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void heli_6_5_update2(void)            /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S5>/Rate Transition: x' */
  heli_6_5_DW.RateTransitionx_Buffer0 = heli_6_5_B.GameController_o4;

  /* Update for RateTransition: '<S5>/Rate Transition: y' */
  heli_6_5_DW.RateTransitiony_Buffer0 = heli_6_5_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_6_5_M->Timing.clockTick2)) {
    ++heli_6_5_M->Timing.clockTickH2;
  }

  heli_6_5_M->Timing.t[2] = heli_6_5_M->Timing.clockTick2 *
    heli_6_5_M->Timing.stepSize2 + heli_6_5_M->Timing.clockTickH2 *
    heli_6_5_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_6_5_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_6_5_output0();
    break;

   case 2 :
    heli_6_5_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_6_5_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_6_5_update0();
    break;

   case 2 :
    heli_6_5_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_6_5_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_6_5/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_6_5_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_6_5_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_6_5_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
      return;
    }

    if ((heli_6_5_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (heli_6_5_P.HILInitialize_set_analog_inpu_n && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_6_5_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = heli_6_5_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_6_5_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_6_5_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(heli_6_5_DW.HILInitialize_Card,
        heli_6_5_P.HILInitialize_analog_input_chan, 8U,
        &heli_6_5_DW.HILInitialize_AIMinimums[0],
        &heli_6_5_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }
    }

    if ((heli_6_5_P.HILInitialize_set_analog_output && !is_switching) ||
        (heli_6_5_P.HILInitialize_set_analog_outp_f && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_6_5_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = heli_6_5_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_6_5_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_6_5_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(heli_6_5_DW.HILInitialize_Card,
        heli_6_5_P.HILInitialize_analog_output_cha, 8U,
        &heli_6_5_DW.HILInitialize_AOMinimums[0],
        &heli_6_5_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }
    }

    if ((heli_6_5_P.HILInitialize_set_analog_outp_d && !is_switching) ||
        (heli_6_5_P.HILInitialize_set_analog_outp_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_6_5_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_6_5_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(heli_6_5_DW.HILInitialize_Card,
        heli_6_5_P.HILInitialize_analog_output_cha, 8U,
        &heli_6_5_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }
    }

    if (heli_6_5_P.HILInitialize_set_analog_outp_h) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_6_5_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_6_5_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_6_5_DW.HILInitialize_Card,
         heli_6_5_P.HILInitialize_analog_output_cha, 8U,
         &heli_6_5_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }
    }

    if ((heli_6_5_P.HILInitialize_set_encoder_param && !is_switching) ||
        (heli_6_5_P.HILInitialize_set_encoder_par_o && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_6_5_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_6_5_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(heli_6_5_DW.HILInitialize_Card,
        heli_6_5_P.HILInitialize_encoder_channels, 8U,
        (t_encoder_quadrature_mode *)
        &heli_6_5_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }
    }

    if ((heli_6_5_P.HILInitialize_set_encoder_count && !is_switching) ||
        (heli_6_5_P.HILInitialize_set_encoder_cou_n && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_6_5_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_6_5_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(heli_6_5_DW.HILInitialize_Card,
        heli_6_5_P.HILInitialize_encoder_channels, 8U,
        &heli_6_5_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }
    }

    if ((heli_6_5_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (heli_6_5_P.HILInitialize_set_pwm_params__o && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_6_5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_6_5_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(heli_6_5_DW.HILInitialize_Card,
        heli_6_5_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &heli_6_5_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          heli_6_5_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &heli_6_5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            heli_6_5_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            heli_6_5_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_6_5_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            heli_6_5_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            heli_6_5_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              heli_6_5_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_6_5_DW.HILInitialize_Card,
          &heli_6_5_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &heli_6_5_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_6_5_DW.HILInitialize_Card,
          &heli_6_5_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_6_5_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_6_5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_6_5_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &heli_6_5_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_6_5_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &heli_6_5_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_6_5_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(heli_6_5_DW.HILInitialize_Card,
        heli_6_5_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &heli_6_5_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_6_5_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_6_5_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &heli_6_5_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_6_5_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_6_5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_6_5_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(heli_6_5_DW.HILInitialize_Card,
        heli_6_5_P.HILInitialize_pwm_channels, 8U,
        &heli_6_5_DW.HILInitialize_POSortedFreqs[0],
        &heli_6_5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }
    }

    if ((heli_6_5_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (heli_6_5_P.HILInitialize_set_pwm_outputs_k && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_6_5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_6_5_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(heli_6_5_DW.HILInitialize_Card,
        heli_6_5_P.HILInitialize_pwm_channels, 8U,
        &heli_6_5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }
    }

    if (heli_6_5_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_6_5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_6_5_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_6_5_DW.HILInitialize_Card, heli_6_5_P.HILInitialize_pwm_channels,
         8U, &heli_6_5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_6_5/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_6_5_DW.HILInitialize_Card,
      heli_6_5_P.HILReadEncoderTimebase_samples_,
      heli_6_5_P.HILReadEncoderTimebase_channels, 3,
      &heli_6_5_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S5>/Rate Transition: x' */
  heli_6_5_B.RateTransitionx = heli_6_5_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S5>/Rate Transition: y' */
  heli_6_5_B.RateTransitiony = heli_6_5_P.RateTransitiony_X0;

  /* Start for S-Function (stream_call_block): '<S4>/Stream Call1' */

  /* S-Function Block: heli_6_5/IMU/Stream Call1 (stream_call_block) */
  {
    heli_6_5_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_6_5_DW.StreamCall1_Stream = NULL;
  }

  /* Start for S-Function (game_controller_block): '<S5>/Game Controller' */

  /* S-Function Block: heli_6_5/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_6_5_P.GameController_Enabled) {
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

      result = game_controller_open(heli_6_5_P.GameController_ControllerNumber,
        heli_6_5_P.GameController_BufferSize, deadzone, saturation,
        heli_6_5_P.GameController_AutoCenter, 0, 1.0,
        &heli_6_5_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
      }
    }
  }

  heli_6_5_PrevZCX.Subsystem6_Trig_ZCE = POS_ZCSIG;
  heli_6_5_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      heli_6_5_DW.UnitDelay_DSTATE[i] = heli_6_5_P.x_0[i];
    }

    /* End of InitializeConditions for UnitDelay: '<Root>/Unit Delay' */

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition: x' */
    heli_6_5_DW.RateTransitionx_Buffer0 = heli_6_5_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition: y' */
    heli_6_5_DW.RateTransitiony_Buffer0 = heli_6_5_P.RateTransitiony_X0;

    /* InitializeConditions for Triggered SubSystem: '<Root>/Triggered Subsystem' */
    /* InitializeConditions for UnitDelay: '<S10>/Unit Delay1' */
    memcpy(&heli_6_5_DW.UnitDelay1_DSTATE[0], &heli_6_5_P.P_0[0], 36U * sizeof
           (real_T));

    /* End of InitializeConditions for SubSystem: '<Root>/Triggered Subsystem' */

    /* InitializeConditions for TransferFcn: '<S3>/Travel: Transfer Fcn' */
    heli_6_5_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
    heli_6_5_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
    heli_6_5_X.ElevationTransferFcn_CSTATE = 0.0;
  }
}

/* Model terminate function */
void heli_6_5_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_6_5/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_6_5_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_6_5_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_6_5_P.HILInitialize_set_analog_out_jf && !is_switching) ||
        (heli_6_5_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_6_5_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_6_5_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_6_5_P.HILInitialize_set_pwm_outputs_d && !is_switching) ||
        (heli_6_5_P.HILInitialize_set_pwm_outputs_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_6_5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_6_5_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_6_5_DW.HILInitialize_Card
                         , heli_6_5_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , heli_6_5_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_6_5_DW.HILInitialize_AOVoltages[0]
                         , &heli_6_5_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_6_5_DW.HILInitialize_Card,
            heli_6_5_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
            &heli_6_5_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_6_5_DW.HILInitialize_Card,
            heli_6_5_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &heli_6_5_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_6_5_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_6_5_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_6_5_DW.HILInitialize_Card);
    hil_close(heli_6_5_DW.HILInitialize_Card);
    heli_6_5_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S4>/Stream Call1' */

  /* S-Function Block: heli_6_5/IMU/Stream Call1 (stream_call_block) */
  {
    if (heli_6_5_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_6_5_DW.StreamCall1_Stream);
      heli_6_5_DW.StreamCall1_Stream = NULL;
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S5>/Game Controller' */

  /* S-Function Block: heli_6_5/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_6_5_P.GameController_Enabled) {
      game_controller_close(heli_6_5_DW.GameController_Controller);
      heli_6_5_DW.GameController_Controller = NULL;
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
  heli_6_5_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_6_5_update(tid);
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
  heli_6_5_initialize();
}

void MdlTerminate(void)
{
  heli_6_5_terminate();
}

/* Registration function */
RT_MODEL_heli_6_5_T *heli_6_5(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  heli_6_5_P.Constant2_Value = rtNaN;

  /* initialize real-time model */
  (void) memset((void *)heli_6_5_M, 0,
                sizeof(RT_MODEL_heli_6_5_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_6_5_M->solverInfo,
                          &heli_6_5_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_6_5_M->solverInfo, &rtmGetTPtr(heli_6_5_M));
    rtsiSetStepSizePtr(&heli_6_5_M->solverInfo, &heli_6_5_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_6_5_M->solverInfo, &heli_6_5_M->ModelData.derivs);
    rtsiSetContStatesPtr(&heli_6_5_M->solverInfo, (real_T **)
                         &heli_6_5_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&heli_6_5_M->solverInfo,
      &heli_6_5_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_6_5_M->solverInfo,
      &heli_6_5_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_6_5_M->solverInfo,
      &heli_6_5_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_6_5_M->solverInfo,
      &heli_6_5_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_6_5_M->solverInfo, (&rtmGetErrorStatus
      (heli_6_5_M)));
    rtsiSetRTModelPtr(&heli_6_5_M->solverInfo, heli_6_5_M);
  }

  rtsiSetSimTimeStep(&heli_6_5_M->solverInfo, MAJOR_TIME_STEP);
  heli_6_5_M->ModelData.intgData.f[0] = heli_6_5_M->ModelData.odeF[0];
  heli_6_5_M->ModelData.contStates = ((real_T *) &heli_6_5_X);
  rtsiSetSolverData(&heli_6_5_M->solverInfo, (void *)
                    &heli_6_5_M->ModelData.intgData);
  rtsiSetSolverName(&heli_6_5_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_6_5_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_6_5_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_6_5_M->Timing.sampleTimes = (&heli_6_5_M->Timing.sampleTimesArray[0]);
    heli_6_5_M->Timing.offsetTimes = (&heli_6_5_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_6_5_M->Timing.sampleTimes[0] = (0.0);
    heli_6_5_M->Timing.sampleTimes[1] = (0.002);
    heli_6_5_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_6_5_M->Timing.offsetTimes[0] = (0.0);
    heli_6_5_M->Timing.offsetTimes[1] = (0.0);
    heli_6_5_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_6_5_M, &heli_6_5_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_6_5_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_6_5_M->Timing.perTaskSampleHitsArray;
    heli_6_5_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_6_5_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_6_5_M, -1);
  heli_6_5_M->Timing.stepSize0 = 0.002;
  heli_6_5_M->Timing.stepSize1 = 0.002;
  heli_6_5_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_6_5_M->Sizes.checksums[0] = (3448498446U);
  heli_6_5_M->Sizes.checksums[1] = (2879067277U);
  heli_6_5_M->Sizes.checksums[2] = (1171563730U);
  heli_6_5_M->Sizes.checksums[3] = (1185534661U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    heli_6_5_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&heli_6_5_DW.Subsystem6_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&heli_6_5_DW.TriggeredSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&heli_6_5_DW.TriggeredSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(heli_6_5_M->extModeInfo,
      &heli_6_5_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_6_5_M->extModeInfo, heli_6_5_M->Sizes.checksums);
    rteiSetTPtr(heli_6_5_M->extModeInfo, rtmGetTPtr(heli_6_5_M));
  }

  heli_6_5_M->solverInfoPtr = (&heli_6_5_M->solverInfo);
  heli_6_5_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_6_5_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_6_5_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_6_5_M->ModelData.blockIO = ((void *) &heli_6_5_B);
  (void) memset(((void *) &heli_6_5_B), 0,
                sizeof(B_heli_6_5_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_6_5_B.UnitDelay[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_6_5_B.Gain[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_6_5_B.Sum3[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_6_5_B.UnitDelay1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_6_5_B.xk1[i] = 0.0;
    }

    heli_6_5_B.RateTransitionx = 0.0;
    heli_6_5_B.Joystick_gain_x = 0.0;
    heli_6_5_B.RateTransitiony = 0.0;
    heli_6_5_B.Joystick_gain_y = 0.0;
    heli_6_5_B.TravelCounttorad = 0.0;
    heli_6_5_B.TravelTransferFcn = 0.0;
    heli_6_5_B.PitchCounttorad = 0.0;
    heli_6_5_B.Sum1 = 0.0;
    heli_6_5_B.PitchTransferFcn = 0.0;
    heli_6_5_B.ElevationCounttorad = 0.0;
    heli_6_5_B.Sum = 0.0;
    heli_6_5_B.ElevationTransferFcn = 0.0;
    heli_6_5_B.GameController_o4 = 0.0;
    heli_6_5_B.GameController_o5 = 0.0;
    heli_6_5_B.Sum_i = 0.0;
    heli_6_5_B.Sum1_h = 0.0;
    heli_6_5_B.Sum2 = 0.0;
  }

  /* parameters */
  heli_6_5_M->ModelData.defaultParam = ((real_T *)&heli_6_5_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_6_5_X;
    heli_6_5_M->ModelData.contStates = (x);
    (void) memset((void *)&heli_6_5_X, 0,
                  sizeof(X_heli_6_5_T));
  }

  /* states (dwork) */
  heli_6_5_M->ModelData.dwork = ((void *) &heli_6_5_DW);
  (void) memset((void *)&heli_6_5_DW, 0,
                sizeof(DW_heli_6_5_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_6_5_DW.UnitDelay_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      heli_6_5_DW.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_6_5_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_6_5_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_6_5_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_6_5_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_6_5_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_6_5_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_6_5_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_6_5_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_6_5_DW.RateTransitionx_Buffer0 = 0.0;
  heli_6_5_DW.RateTransitiony_Buffer0 = 0.0;
  heli_6_5_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_6_5_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_6_5_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_6_5_M->Sizes.numContStates = (3);/* Number of continuous states */
  heli_6_5_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  heli_6_5_M->Sizes.numY = (0);        /* Number of model outputs */
  heli_6_5_M->Sizes.numU = (0);        /* Number of model inputs */
  heli_6_5_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_6_5_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_6_5_M->Sizes.numBlocks = (93);  /* Number of blocks */
  heli_6_5_M->Sizes.numBlockIO = (25); /* Number of block outputs */
  heli_6_5_M->Sizes.numBlockPrms = (653);/* Sum of parameter "widths" */
  return heli_6_5_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
