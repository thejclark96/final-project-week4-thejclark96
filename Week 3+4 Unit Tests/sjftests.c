// #include <stdlib.h>
// #include <stdbool.h>
// #include "ctest.h"
// #include <time.h>


// CTEST_DATA(shortestjobfirst) {
//     // struct task_t task[4];
//     int size;
// };

// CTEST_SETUP(shortestjobfirst) {
//     int execution[] = {4, 6, 3, 5};
//     data->size = sizeof(execution) / sizeof(execution[0]);

//     init(data->task, execution, data->size);
//     shortest_job_first(data->task, data->size);
// }
// // task ID 0 = 3
// CTEST2(shortestjobfirst, test_process1) {
//     ASSERT_EQUAL(3, (int)data->task[0].waiting_time);
// }

// CTEST2(shortestjobfirst, test_process2) {
//     ASSERT_EQUAL(4, (int)data->task[0].execution_time);
// }

// CTEST2(shortestjobfirst, test_process3) {
//     ASSERT_EQUAL(7, (int)data->task[0].turnaround_time);
// }



// // task ID 1 = 4
// CTEST2(shortestjobfirst, test_process4) {
//     ASSERT_EQUAL(12, (int)data->task[1].waiting_time);
// }

// CTEST2(shortestjobfirst, test_process5) {
//     ASSERT_EQUAL(6, (int)data->task[1].execution_time);
// }

// CTEST2(shortestjobfirst, test_process6) {
//     ASSERT_EQUAL(18, (int)data->task[1].turnaround_time);
// }


// // task ID 2 = 5
// CTEST2(shortestjobfirst, test_process7) {
//     ASSERT_EQUAL(0, (int)data->task[2].waiting_time);
// }

// CTEST2(shortestjobfirst, test_process8) {
//     ASSERT_EQUAL(3, (int)data->task[2].execution_time);
// }

// CTEST2(shortestjobfirst, test_process9) {
//     ASSERT_EQUAL(3, (int)data->task[2].turnaround_time);
// }


// // task ID 3 = 6
// CTEST2(shortestjobfirst, test_process10) {
//     ASSERT_EQUAL(7, (int)data->task[3].waiting_time);
// }

// CTEST2(shortestjobfirst, test_process11) {
//     ASSERT_EQUAL(5, (int)data->task[3].execution_time);
// }

// CTEST2(shortestjobfirst, test_process12) {
//     ASSERT_EQUAL(12, (int)data->task[3].turnaround_time);
// }