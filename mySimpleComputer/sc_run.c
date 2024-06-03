// #include <console.h>
// #include <mySimpleComputer.h>

// int
// run ()
// {
//   enum keys key;
//   if (!sc_consoleInit ())
//     {
//       char buf[30];
//       int len = sprintf (buf, "Error: window is too small!\n");
//       write (1, buf, len);
//       return 0;
//     }
//   sc_regInit ();
//   sc_memoryInit ();
//   sc_icounterInit ();
//   sc_accumulatorInit ();
//   sc_memorySet (0, 0x00);
//   mt_clrscr ();
//   bc_box (1, 86, 3, 24, LIGHT_GRAY, BLACK, " Аккумулятор ", RED, BLACK);
//   bc_box (1, 1, 15, 62, LIGHT_GRAY, BLACK, " Память ", RED, BLACK);
//   bc_box (4, 86, 3, 24, LIGHT_GRAY, BLACK, " Команда ", RED, BLACK);
//   bc_box (4, 63, 3, 23, LIGHT_GRAY, BLACK, " Счетчик ", RED, BLACK);
//   bc_box (1, 63, 3, 23, LIGHT_GRAY, BLACK, " Флаги ", RED, BLACK);
//   bc_box (16, 1, 3, 62, LIGHT_GRAY, BLACK, " Редактируемая ячейка (формат)
//   ",
//           RED, BLACK);
//   bc_box (7, 63, 12, 47, LIGHT_GRAY, BLACK, "", RED, BLACK);
//   sc_printAll ();
//   sc_regSet (FLAG_INCORRECT_COMMAND, 1);
//   while (1)
//     {
//       rk_readkey (&key);
//       int val;
//       if (key == key_esc)
//         {
//           break;
//         }
//       else if (!sc_regGet (FLAG_INCORRECT_COMMAND, &val) && val)
//         {
//           //   strcpy (io_msg, "");
//           switch (key)
//             {
//             case key_l:
//               keyLoad ();
//               break;
//             case key_s:
//               keySave ();
//               break;
//             case key_r:
//               // sc_regSet (FLAG_INCORRECT_COMMAND, 0);
//               comand_counter = 0;
//               ActiveCell = 0;
//               resetTerm ();
//               break;
//             case key_tt:
//               //   Cu ();
//               break;
//             case key_i:
//               //   create_timer (0);
//               //   raise (SIGUSR1);
//               break;
//             case key_f5:
//               keyF5 ();
//               break;
//             case key_f6:
//               keyF6 ();
//               break;
//             case key_up:
//               keyUp ();
//               break;
//             case key_down:
//               keyDown ();
//               break;
//             case key_right:
//               keyRight ();
//               break;
//             case key_left:
//               keyLeft ();
//               break;

//             default:
//               //   key_num (key);
//               break;
//             }
//         }
//     }
//   rk_mytermregime (1, 0, 1, 0, 0);
//   return 0;
// }