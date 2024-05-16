#if ((defined VAR_SEC_OPEN) && ((defined START_SEC_VAR_8BIT) ||                    \
                                (defined START_SEC_VAR_16BIT) ||                   \
                                (defined START_SEC_VAR_32BIT) ||                   \
                                (defined START_SEC_VAR_UNSPECIFIED) ||             \
                                (defined START_SEC_VAR_NOINIT_8BIT) ||             \
                                (defined START_SEC_VAR_NOINIT_16BIT) ||            \
                                (defined START_SEC_VAR_NOINIT_32BIT) ||            \
                                (defined START_SEC_VAR_NOINIT_UNSPECIFIED) ||      \
                                (defined START_SEC_VAR_STBY_8BIT) ||               \
                                (defined START_SEC_VAR_STBY_16BIT) ||              \
                                (defined START_SEC_VAR_STBY_32BIT) ||              \
                                (defined START_SEC_VAR_STBY_UNSPECIFIED) ||        \
                                (defined START_SEC_VAR_FAST_8BIT) ||               \
                                (defined START_SEC_VAR_FAST_16BIT) ||              \
                                (defined START_SEC_VAR_FAST_32BIT) ||              \
                                (defined START_SEC_VAR_FAST_UNSPECIFIED) ||        \
                                (defined START_SEC_VAR_FAST_NOINIT_8BIT) ||        \
                                (defined START_SEC_VAR_FAST_NOINIT_16BIT) ||       \
                                (defined START_SEC_VAR_FAST_NOINIT_32BIT) ||       \
                                (defined START_SEC_VAR_FAST_NOINIT_UNSPECIFIED) || \
                                (defined START_SEC_VAR_CAL_8BIT) ||                \
                                (defined START_SEC_VAR_CAL_16BIT) ||               \
                                (defined START_SEC_VAR_CAL_32BIT) ||               \
                                (defined START_SEC_VAR_CAL_UNSPECIFIED) ||         \
                                (defined START_SEC_CONST_8BIT) ||                  \
                                (defined START_SEC_CONST_16BIT) ||                 \
                                (defined START_SEC_CONST_32BIT) ||                 \
                                (defined START_SEC_CONST_UNSPECIFIED) ||           \
                                0))
#error("MemMap - Var section already open")
#endif

/*Section start*/
#if defined(START_SEC_CODE)
#undef START_SEC_CODE
#define CODE_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_8BIT)
#undef START_SEC_VAR_8BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_16BIT)
#undef START_SEC_VAR_16BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_32BIT)
#undef START_SEC_VAR_32BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_UNSPECIFIED)
#undef START_SEC_VAR_UNSPECIFIED
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_NOINIT_8BIT)
#undef START_SEC_VAR_NOINIT_8BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_NOINIT_16BIT)
#undef START_SEC_VAR_NOINIT_16BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_NOINIT_32BIT)
#undef START_SEC_VAR_NOINIT_32BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_NOINIT_UNSPECIFIED)
#undef START_SEC_VAR_NOINIT_UNSPECIFIED
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_STBY_8BIT)
#undef START_SEC_VAR_STBY_8BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_STBY_16BIT)
#undef START_SEC_VAR_STBY_16BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_STBY_32BIT)
#undef START_SEC_VAR_STBY_32BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_STBY_UNSPECIFIED)
#undef START_SEC_VAR_STBY_UNSPECIFIED
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_VAR_FAST_8BIT)
#undef START_SEC_VAR_FAST_8BIT
#define VAR_SEC_OPEN
#pragma push
#pragma pack(1)
#pragma section all_types ".fast_8bit" \
                          ".fast_8bit"

#elif defined(START_SEC_VAR_FAST_16BIT)
#undef START_SEC_VAR_FAST_16BIT
#define VAR_SEC_OPEN
#pragma push
#pragma pack(1)
#pragma misaligned_mem_access off
#pragma section all_types ".fast_16bit" \
                          ".fast_16bit"

#elif defined(START_SEC_VAR_FAST_32BIT)
#undef START_SEC_VAR_FAST_32BIT
#define VAR_SEC_OPEN
#pragma push
#pragma pack(4)
#pragma section all_types ".fast_32bit" \
                          ".fast_32bit"

#elif defined(START_SEC_VAR_FAST_UNSPECIFIED)
#undef START_SEC_VAR_FAST_UNSPECIFIED
#define VAR_SEC_OPEN
#pragma push
#pragma section all_types ".fast_unspecified" \
                          ".fast_unspecified"

#elif defined(START_SEC_VAR_FAST_NOINIT_8BIT)
#undef START_SEC_VAR_FAST_NOINIT_8BIT
#define VAR_SEC_OPEN
#pragma push
#pragma pack(1)
#pragma section all_types ".fast_8bit" \
                          ".fast_8bit"

#elif defined(START_SEC_VAR_FAST_NOINIT_16BIT)
#undef START_SEC_VAR_FAST_NOINIT_16BIT
#define VAR_SEC_OPEN
#pragma push
#pragma pack(1)
#pragma misaligned_mem_access off
#pragma section all_types ".fast_16bit" \
                          ".fast_16bit"

#elif defined(START_SEC_VAR_FAST_NOINIT_32BIT)
#undef START_SEC_VAR_FAST_NOINIT_32BIT
#define VAR_SEC_OPEN
#pragma push
#pragma pack(4)
#pragma section all_types ".fast_32bit" \
                          ".fast_32bit"

#elif defined(START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
#undef START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#define VAR_SEC_OPEN
#pragma push
#pragma pack(4)
#pragma section all_types ".fast_unspecified" \
                          ".fast_unspecified"

#elif defined(START_SEC_VAR_CAL_8BIT)
#undef START_SEC_VAR_CAL_8BIT
#define VAR_SEC_OPEN
#define push
#pragma pack(1)
#pragma section all_types ".cal_8bit" \
                          ".cal_8bit"

#elif defined(START_SEC_VAR_CAL_16BIT)
#undef START_SEC_VAR_CAL_16BIT
#define VAR_SEC_OPEN
#pragma push
#pragma pack(1)
#pragma misaligned_mem_access off
#pragma section all_types ".cal_16bit" \
                          ".cal_16bit"

#elif defined(START_SEC_VAR_CAL_32BIT)
#undef START_SEC_VAR_CAL_32BIT
#define VAR_SEC_OPEN
#pragma push
#pragma pack(4)
#pragma section all_types ".cal_32bit" \
                          ".cal_32bit"

#elif defined(START_SEC_VAR_CAL_UNSPECIFIED)
#undef START_SEC_VAR_CAL_UNSPECIFIED
#define VAR_SEC_OPEN
#pragma push
#pragma pack(4)
#pragma section all_types ".cal_unspecified" \
                          ".cal_unspecified"

#elif defined(START_SEC_CONST_8BIT)
#undef START_SEC_CONST_8BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_CONST_16BIT)
#undef START_SEC_CONST_16BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_CONST_32BIT)
#undef START_SEC_CONST_32BIT
#define VAR_SEC_OPEN
#pragma push

#elif defined(START_SEC_CONST_UNSPECIFIED)
#undef START_SEC_CONST_UNSPECIFIED
#define VAR_SEC_OPEN
#pragma push

/*Section stops*/

#elif defined(STOP_SEC_VAR_8BIT)
#undef STOP_SEC_VAR_8BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_16BIT)
#undef STOP_SEC_VAR_16BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_32BIT)
#undef STOP_SEC_VAR_32BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_UNSPECIFIED)
#undef STOP_SEC_VAR_UNSPECIFIED
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_NOINIT_8BIT)
#undef STOP_SEC_VAR_NOINIT_8BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_NOINIT_16BIT)
#undef STOP_SEC_VAR_NOINIT_16BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_NOINIT_32BIT)
#undef STOP_SEC_VAR_NOINIT_32BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_NOINIT_UNSPECIFIED)
#undef STOP_SEC_VAR_NOINIT_UNSPECIFIED
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_STBY_8BIT)
#undef STOP_SEC_VAR_STBY_8BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_STBY_16BIT)
#undef STOP_SEC_VAR_STBY_16BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_STBY_32BIT)
#undef STOP_SEC_VAR_STBY_32BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_STBY_UNSPECIFIED)
#undef STOP_SEC_VAR_STBY_UNSPECIFIED
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_FAST_8BIT)
#undef STOP_SEC_VAR_FAST_8BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_FAST_16BIT)
#undef STOP_SEC_VAR_FAST_16BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_FAST_32BIT)
#undef STOP_SEC_VAR_FAST_32BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_FAST_UNSPECIFIED)
#undef STOP_SEC_VAR_FAST_UNSPECIFIED
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_FAST_NOINIT_8BIT)
#undef STOP_SEC_VAR_FAST_NOINIT_8BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_FAST_NOINIT_16BIT)
#undef STOP_SEC_VAR_FAST_NOINIT_16BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_FAST_NOINIT_32BIT)
#undef STOP_SEC_VAR_FAST_NOINIT_32BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
#undef STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_CAL_8BIT)
#undef STOP_SEC_VAR_CAL_8BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_CAL_16BIT)
#undef STOP_SEC_VAR_CAL_16BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_CAL_32BIT)
#undef STOP_SEC_VAR_CAL_32BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_VAR_CAL_UNSPECIFIED)
#undef STOP_SEC_VAR_CAL_UNSPECIFIED
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_CONST_8BIT)
#undef STOP_SEC_CONST_8BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_CONST_16BIT)
#undef STOP_SEC_CONST_16BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_CONST_32BIT)
#undef STOP_SEC_CONST_32BIT
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_CONST_UNSPECIFIED)
#undef STOP_SEC_CONST_UNSPECIFIED
#undef VAR_SEC_OPEN
#pragma pop

#elif defined(STOP_SEC_CODE)
#undef STOP_SEC_CODE
#undef CODE_SEC_OPEN
#pragma pop
#endif

#ifdef BSW_MEMMAP_ERROR
#error("BSW_MemMap error - no matching section")
#endif
