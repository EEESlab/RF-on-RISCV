#include "pmsis.h"
#include "params.h"
#include "data.h"


/* Testing Data */


#ifdef  VEHICLE

/* VEHICLE Dataset */
/* Total L1 Memory Requirements = 0.76kB */

PI_CL_L1 float x_test[DIM*N_TEST] = {

 84.000000, 47.000000, 75.000000, 153.000000, 64.000000, 6.000000, 154.000000, 43.000000, 19.000000, 145.000000, 175.000000, 354.000000, 184.000000, 75.000000, 0.000000, 3.000000, 185.000000, 192.000000,
 96.000000, 44.000000, 68.000000, 190.000000, 70.000000, 7.000000, 155.000000, 41.000000, 19.000000, 145.000000, 179.000000, 372.000000, 166.000000, 67.000000, 5.000000, 7.000000, 202.000000, 206.000000,
 104.000000, 54.000000, 101.000000, 197.000000, 64.000000, 11.000000, 213.000000, 31.000000, 24.000000, 172.000000, 218.000000, 669.000000, 222.000000, 74.000000, 14.000000, 4.000000, 187.000000, 196.000000,
 83.000000, 44.000000, 68.000000, 144.000000, 61.000000, 8.000000, 147.000000, 45.000000, 19.000000, 143.000000, 170.000000, 325.000000, 180.000000, 74.000000, 1.000000, 1.000000, 185.000000, 191.000000,
 94.000000, 46.000000, 79.000000, 181.000000, 62.000000, 8.000000, 167.000000, 40.000000, 20.000000, 148.000000, 190.000000, 418.000000, 193.000000, 67.000000, 12.000000, 15.000000, 191.000000, 198.000000,
 86.000000, 39.000000, 58.000000, 125.000000, 55.000000, 5.000000, 117.000000, 57.000000, 17.000000, 134.000000, 140.000000, 204.000000, 148.000000, 69.000000, 7.000000, 6.000000, 190.000000, 194.000000,
 80.000000, 39.000000, 60.000000, 122.000000, 56.000000, 6.000000, 139.000000, 49.000000, 18.000000, 131.000000, 151.000000, 281.000000, 142.000000, 80.000000, 0.000000, 5.000000, 179.000000, 186.000000,
 89.000000, 41.000000, 63.000000, 134.000000, 59.000000, 6.000000, 123.000000, 55.000000, 17.000000, 137.000000, 148.000000, 223.000000, 150.000000, 76.000000, 12.000000, 3.000000, 186.000000, 188.000000,
 89.000000, 41.000000, 76.000000, 183.000000, 73.000000, 7.000000, 157.000000, 42.000000, 19.000000, 136.000000, 181.000000, 373.000000, 153.000000, 74.000000, 8.000000, 12.000000, 191.000000, 195.000000,
 106.000000, 49.000000, 106.000000, 211.000000, 64.000000, 9.000000, 208.000000, 32.000000, 24.000000, 158.000000, 224.000000, 645.000000, 184.000000, 68.000000, 1.000000, 24.000000, 190.000000, 202.000000,

};

PI_CL_L1 int y_test[N_TEST] = {

 2, 2, 1, 2, 3, 0, 3, 0, 2, 1,

};

#endif 


#ifdef  MFEAT_FACTORS

/* MFEAT-FACTORS Dataset */
/* Total L1 Memory Requirements = 8.68kB */

PI_CL_L1 float x_test[DIM*N_TEST] = {

 425.000000, 285.000000, 626.000000, 891.000000, 701.000000, 578.000000, 6.000000, 19.000000, 15.000000, 9.000000, 6.000000, 11.000000, 204.000000, 330.000000, 679.000000, 796.000000, 636.000000, 947.000000, 1.000000, 12.000000, 16.000000, 2.000000, 4.000000, 9.000000, 262.000000, 524.000000, 688.000000, 693.000000, 735.000000, 658.000000, 30.000000, 32.000000, 6.000000, 6.000000, 16.000000, 18.000000, 430.000000, 468.000000, 632.000000, 864.000000, 668.000000, 857.000000, 30.000000, 34.000000, 16.000000, 13.000000, 12.000000, 19.000000, 347.000000, 481.000000, 644.000000, 808.000000, 760.000000, 677.000000, 31.000000, 34.000000, 6.000000, 10.000000, 11.000000, 12.000000, 381.000000, 421.000000, 509.000000, 664.000000, 691.000000, 657.000000, 30.000000, 32.000000, 7.000000, 8.000000, 16.000000, 20.000000, 283.000000, 369.000000, 704.000000, 709.000000, 625.000000, 1017.000000, 5.000000, 20.000000, 16.000000, 1.000000, 16.000000, 16.000000, 249.000000, 183.000000, 671.000000, 736.000000, 667.000000, 859.000000, 2.000000, 14.000000, 9.000000, 6.000000, 9.000000, 4.000000, 124.000000, 274.000000, 766.000000, 890.000000, 753.000000, 941.000000, 18.000000, 3.000000, 8.000000, 1.000000, 6.000000, 3.000000, 546.000000, 410.000000, 630.000000, 652.000000, 662.000000, 670.000000, 22.000000, 14.000000, 34.000000, 12.000000, 13.000000, 20.000000, 313.000000, 367.000000, 534.000000, 645.000000, 610.000000, 672.000000, 21.000000, 9.000000, 12.000000, 16.000000, 11.000000, 14.000000, 527.000000, 307.000000, 715.000000, 964.000000, 545.000000, 698.000000, 15.000000, 18.000000, 11.000000, 15.000000, 7.000000, 19.000000, 335.000000, 191.000000, 691.000000, 976.000000, 647.000000, 630.000000, 13.000000, 16.000000, 9.000000, 0.000000, 4.000000, 6.000000, 249.000000, 259.000000, 601.000000, 702.000000, 635.000000, 925.000000, 10.000000, 13.000000, 1.000000, 2.000000, 16.000000, 15.000000, 377.000000, 281.000000, 538.000000, 491.000000, 587.000000, 701.000000, 13.000000, 27.000000, 2.000000, 9.000000, 15.000000, 22.000000, 553.000000, 387.000000, 692.000000, 588.000000, 776.000000, 530.000000, 21.000000, 17.000000, 26.000000, 9.000000, 11.000000, 21.000000, 257.000000, 201.000000, 907.000000, 949.000000, 679.000000, 1153.000000, 12.000000, 6.000000, 8.000000, 3.000000, 9.000000, 11.000000, 286.000000, 328.000000, 617.000000, 858.000000, 734.000000, 589.000000, 14.000000, 26.000000, 18.000000, 16.000000, 14.000000, 3.000000,
 116.000000, 188.000000, 618.000000, 657.000000, 594.000000, 660.000000, 9.000000, 5.000000, 9.000000, 4.000000, 6.000000, 1.000000, 189.000000, 291.000000, 597.000000, 600.000000, 607.000000, 983.000000, 4.000000, 24.000000, 22.000000, 9.000000, 4.000000, 13.000000, 255.000000, 419.000000, 640.000000, 563.000000, 948.000000, 734.000000, 27.000000, 26.000000, 12.000000, 15.000000, 8.000000, 14.000000, 335.000000, 413.000000, 706.000000, 706.000000, 791.000000, 935.000000, 33.000000, 30.000000, 22.000000, 12.000000, 10.000000, 9.000000, 272.000000, 386.000000, 680.000000, 734.000000, 889.000000, 753.000000, 28.000000, 30.000000, 12.000000, 11.000000, 9.000000, 6.000000, 214.000000, 308.000000, 499.000000, 708.000000, 980.000000, 713.000000, 27.000000, 24.000000, 1.000000, 15.000000, 8.000000, 12.000000, 220.000000, 340.000000, 710.000000, 505.000000, 660.000000, 1033.000000, 2.000000, 32.000000, 22.000000, 6.000000, 8.000000, 10.000000, 246.000000, 298.000000, 647.000000, 460.000000, 644.000000, 895.000000, 1.000000, 32.000000, 15.000000, 13.000000, 3.000000, 8.000000, 343.000000, 225.000000, 766.000000, 612.000000, 732.000000, 989.000000, 21.000000, 9.000000, 14.000000, 6.000000, 8.000000, 9.000000, 327.000000, 357.000000, 596.000000, 772.000000, 929.000000, 772.000000, 19.000000, 24.000000, 24.000000, 7.000000, 9.000000, 12.000000, 248.000000, 320.000000, 442.000000, 651.000000, 839.000000, 692.000000, 18.000000, 27.000000, 6.000000, 11.000000, 3.000000, 18.000000, 280.000000, 222.000000, 681.000000, 690.000000, 616.000000, 714.000000, 16.000000, 12.000000, 9.000000, 10.000000, 5.000000, 13.000000, 256.000000, 138.000000, 673.000000, 700.000000, 662.000000, 668.000000, 12.000000, 12.000000, 11.000000, 7.000000, 4.000000, 10.000000, 258.000000, 376.000000, 555.000000, 564.000000, 706.000000, 941.000000, 7.000000, 25.000000, 7.000000, 7.000000, 8.000000, 5.000000, 248.000000, 372.000000, 558.000000, 571.000000, 894.000000, 755.000000, 10.000000, 23.000000, 4.000000, 2.000000, 9.000000, 12.000000, 372.000000, 410.000000, 710.000000, 862.000000, 1119.000000, 626.000000, 18.000000, 7.000000, 20.000000, 4.000000, 11.000000, 11.000000, 372.000000, 318.000000, 841.000000, 715.000000, 594.000000, 1177.000000, 15.000000, 10.000000, 14.000000, 8.000000, 11.000000, 5.000000, 221.000000, 409.000000, 585.000000, 566.000000, 631.000000, 703.000000, 17.000000, 34.000000, 22.000000, 9.000000, 10.000000, 7.000000,
 234.000000, 258.000000, 546.000000, 884.000000, 692.000000, 662.000000, 3.000000, 15.000000, 23.000000, 11.000000, 14.000000, 5.000000, 209.000000, 227.000000, 613.000000, 759.000000, 699.000000, 1029.000000, 8.000000, 22.000000, 8.000000, 4.000000, 12.000000, 19.000000, 295.000000, 443.000000, 644.000000, 694.000000, 914.000000, 742.000000, 39.000000, 20.000000, 2.000000, 10.000000, 0.000000, 12.000000, 295.000000, 381.000000, 670.000000, 867.000000, 849.000000, 939.000000, 27.000000, 24.000000, 8.000000, 17.000000, 12.000000, 9.000000, 218.000000, 396.000000, 640.000000, 801.000000, 925.000000, 761.000000, 40.000000, 24.000000, 2.000000, 14.000000, 13.000000, 12.000000, 340.000000, 378.000000, 493.000000, 647.000000, 948.000000, 743.000000, 39.000000, 18.000000, 15.000000, 12.000000, 6.000000, 10.000000, 216.000000, 340.000000, 726.000000, 712.000000, 684.000000, 1099.000000, 14.000000, 22.000000, 8.000000, 1.000000, 6.000000, 14.000000, 372.000000, 210.000000, 651.000000, 737.000000, 624.000000, 941.000000, 11.000000, 22.000000, 1.000000, 8.000000, 7.000000, 14.000000, 311.000000, 175.000000, 796.000000, 889.000000, 822.000000, 1023.000000, 21.000000, 15.000000, 2.000000, 1.000000, 12.000000, 9.000000, 517.000000, 425.000000, 496.000000, 671.000000, 929.000000, 752.000000, 31.000000, 20.000000, 32.000000, 14.000000, 13.000000, 10.000000, 372.000000, 424.000000, 386.000000, 640.000000, 829.000000, 762.000000, 30.000000, 23.000000, 20.000000, 18.000000, 11.000000, 16.000000, 330.000000, 342.000000, 581.000000, 943.000000, 608.000000, 780.000000, 12.000000, 16.000000, 19.000000, 17.000000, 13.000000, 11.000000, 182.000000, 208.000000, 601.000000, 977.000000, 680.000000, 720.000000, 10.000000, 16.000000, 17.000000, 2.000000, 12.000000, 16.000000, 192.000000, 298.000000, 605.000000, 707.000000, 748.000000, 1011.000000, 19.000000, 15.000000, 7.000000, 0.000000, 0.000000, 11.000000, 402.000000, 328.000000, 558.000000, 548.000000, 876.000000, 787.000000, 22.000000, 23.000000, 10.000000, 7.000000, 1.000000, 10.000000, 492.000000, 550.000000, 630.000000, 661.000000, 1101.000000, 614.000000, 30.000000, 15.000000, 34.000000, 9.000000, 15.000000, 9.000000, 272.000000, 228.000000, 873.000000, 954.000000, 692.000000, 1235.000000, 3.000000, 16.000000, 0.000000, 1.000000, 15.000000, 5.000000, 399.000000, 365.000000, 489.000000, 823.000000, 715.000000, 671.000000, 19.000000, 28.000000, 16.000000, 14.000000, 16.000000, 13.000000,
 332.000000, 452.000000, 976.000000, 776.000000, 651.000000, 831.000000, 37.000000, 27.000000, 19.000000, 11.000000, 9.000000, 15.000000, 285.000000, 281.000000, 719.000000, 683.000000, 692.000000, 960.000000, 32.000000, 16.000000, 20.000000, 22.000000, 15.000000, 7.000000, 265.000000, 95.000000, 794.000000, 672.000000, 1089.000000, 845.000000, 15.000000, 28.000000, 38.000000, 2.000000, 11.000000, 2.000000, 233.000000, 127.000000, 1024.000000, 869.000000, 884.000000, 934.000000, 13.000000, 16.000000, 28.000000, 1.000000, 1.000000, 3.000000, 170.000000, 154.000000, 992.000000, 895.000000, 1000.000000, 844.000000, 0.000000, 6.000000, 38.000000, 2.000000, 2.000000, 12.000000, 200.000000, 246.000000, 835.000000, 859.000000, 1131.000000, 818.000000, 1.000000, 24.000000, 29.000000, 4.000000, 9.000000, 10.000000, 224.000000, 342.000000, 902.000000, 680.000000, 771.000000, 926.000000, 26.000000, 8.000000, 28.000000, 19.000000, 9.000000, 0.000000, 314.000000, 478.000000, 853.000000, 573.000000, 787.000000, 882.000000, 29.000000, 18.000000, 35.000000, 18.000000, 12.000000, 12.000000, 353.000000, 347.000000, 772.000000, 719.000000, 783.000000, 986.000000, 27.000000, 31.000000, 36.000000, 13.000000, 9.000000, 13.000000, 275.000000, 205.000000, 964.000000, 839.000000, 1054.000000, 909.000000, 9.000000, 16.000000, 2.000000, 14.000000, 2.000000, 4.000000, 314.000000, 318.000000, 810.000000, 794.000000, 974.000000, 715.000000, 10.000000, 19.000000, 26.000000, 16.000000, 10.000000, 2.000000, 278.000000, 360.000000, 1049.000000, 783.000000, 745.000000, 755.000000, 28.000000, 32.000000, 31.000000, 15.000000, 8.000000, 3.000000, 314.000000, 476.000000, 951.000000, 807.000000, 813.000000, 729.000000, 30.000000, 22.000000, 31.000000, 16.000000, 13.000000, 10.000000, 312.000000, 356.000000, 645.000000, 743.000000, 815.000000, 926.000000, 21.000000, 15.000000, 41.000000, 18.000000, 11.000000, 13.000000, 292.000000, 348.000000, 860.000000, 668.000000, 1039.000000, 850.000000, 18.000000, 27.000000, 36.000000, 11.000000, 10.000000, 10.000000, 222.000000, 338.000000, 1064.000000, 951.000000, 1266.000000, 817.000000, 10.000000, 31.000000, 30.000000, 11.000000, 4.000000, 7.000000, 374.000000, 586.000000, 837.000000, 854.000000, 643.000000, 1032.000000, 43.000000, 30.000000, 36.000000, 17.000000, 14.000000, 13.000000, 373.000000, 371.000000, 907.000000, 627.000000, 662.000000, 798.000000, 23.000000, 14.000000, 22.000000, 10.000000, 13.000000, 13.000000,
 395.000000, 321.000000, 645.000000, 959.000000, 797.000000, 581.000000, 4.000000, 15.000000, 17.000000, 9.000000, 10.000000, 5.000000, 226.000000, 282.000000, 742.000000, 844.000000, 728.000000, 950.000000, 1.000000, 16.000000, 14.000000, 2.000000, 10.000000, 15.000000, 302.000000, 524.000000, 723.000000, 757.000000, 789.000000, 661.000000, 32.000000, 34.000000, 4.000000, 8.000000, 12.000000, 12.000000, 358.000000, 426.000000, 671.000000, 950.000000, 748.000000, 860.000000, 28.000000, 38.000000, 14.000000, 15.000000, 6.000000, 13.000000, 283.000000, 455.000000, 683.000000, 896.000000, 830.000000, 680.000000, 33.000000, 38.000000, 4.000000, 12.000000, 5.000000, 8.000000, 359.000000, 417.000000, 550.000000, 754.000000, 745.000000, 660.000000, 32.000000, 32.000000, 9.000000, 10.000000, 12.000000, 14.000000, 245.000000, 379.000000, 767.000000, 781.000000, 723.000000, 1020.000000, 7.000000, 24.000000, 14.000000, 1.000000, 10.000000, 18.000000, 239.000000, 215.000000, 734.000000, 800.000000, 725.000000, 862.000000, 4.000000, 14.000000, 7.000000, 6.000000, 7.000000, 10.000000, 114.000000, 216.000000, 831.000000, 952.000000, 833.000000, 944.000000, 20.000000, 1.000000, 6.000000, 1.000000, 0.000000, 5.000000, 482.000000, 428.000000, 641.000000, 726.000000, 730.000000, 673.000000, 24.000000, 18.000000, 36.000000, 12.000000, 17.000000, 14.000000, 269.000000, 421.000000, 559.000000, 733.000000, 668.000000, 675.000000, 23.000000, 13.000000, 14.000000, 16.000000, 11.000000, 14.000000, 481.000000, 341.000000, 726.000000, 1014.000000, 637.000000, 701.000000, 13.000000, 14.000000, 13.000000, 15.000000, 11.000000, 13.000000, 351.000000, 225.000000, 706.000000, 1040.000000, 709.000000, 633.000000, 11.000000, 12.000000, 11.000000, 0.000000, 10.000000, 12.000000, 221.000000, 287.000000, 658.000000, 782.000000, 729.000000, 928.000000, 12.000000, 17.000000, 1.000000, 2.000000, 12.000000, 9.000000, 399.000000, 307.000000, 585.000000, 543.000000, 639.000000, 704.000000, 15.000000, 31.000000, 4.000000, 9.000000, 11.000000, 16.000000, 501.000000, 427.000000, 705.000000, 656.000000, 798.000000, 533.000000, 23.000000, 13.000000, 28.000000, 9.000000, 15.000000, 15.000000, 179.000000, 161.000000, 964.000000, 1025.000000, 773.000000, 1156.000000, 10.000000, 2.000000, 6.000000, 3.000000, 3.000000, 5.000000, 294.000000, 372.000000, 622.000000, 902.000000, 810.000000, 592.000000, 12.000000, 30.000000, 20.000000, 16.000000, 16.000000, 9.000000,
 304.000000, 392.000000, 987.000000, 683.000000, 589.000000, 729.000000, 39.000000, 11.000000, 9.000000, 15.000000, 5.000000, 10.000000, 295.000000, 301.000000, 666.000000, 630.000000, 590.000000, 844.000000, 34.000000, 38.000000, 22.000000, 10.000000, 5.000000, 12.000000, 193.000000, 139.000000, 785.000000, 561.000000, 953.000000, 723.000000, 13.000000, 12.000000, 12.000000, 2.000000, 9.000000, 3.000000, 325.000000, 179.000000, 923.000000, 722.000000, 778.000000, 910.000000, 15.000000, 16.000000, 22.000000, 5.000000, 9.000000, 16.000000, 290.000000, 182.000000, 909.000000, 728.000000, 870.000000, 712.000000, 2.000000, 22.000000, 12.000000, 6.000000, 8.000000, 9.000000, 130.000000, 146.000000, 812.000000, 706.000000, 995.000000, 666.000000, 3.000000, 10.000000, 1.000000, 0.000000, 9.000000, 1.000000, 250.000000, 252.000000, 747.000000, 525.000000, 641.000000, 868.000000, 28.000000, 36.000000, 22.000000, 15.000000, 9.000000, 11.000000, 274.000000, 382.000000, 738.000000, 502.000000, 651.000000, 770.000000, 31.000000, 24.000000, 15.000000, 6.000000, 4.000000, 17.000000, 437.000000, 313.000000, 693.000000, 640.000000, 735.000000, 878.000000, 25.000000, 25.000000, 14.000000, 5.000000, 9.000000, 18.000000, 295.000000, 207.000000, 991.000000, 780.000000, 920.000000, 843.000000, 11.000000, 26.000000, 24.000000, 16.000000, 8.000000, 1.000000, 264.000000, 218.000000, 837.000000, 643.000000, 838.000000, 623.000000, 12.000000, 25.000000, 6.000000, 12.000000, 4.000000, 7.000000, 212.000000, 322.000000, 1076.000000, 720.000000, 609.000000, 675.000000, 30.000000, 12.000000, 9.000000, 11.000000, 4.000000, 2.000000, 336.000000, 322.000000, 1000.000000, 728.000000, 677.000000, 649.000000, 32.000000, 22.000000, 11.000000, 4.000000, 5.000000, 15.000000, 318.000000, 290.000000, 648.000000, 566.000000, 683.000000, 782.000000, 23.000000, 33.000000, 7.000000, 14.000000, 9.000000, 8.000000, 172.000000, 260.000000, 805.000000, 595.000000, 903.000000, 692.000000, 20.000000, 9.000000, 4.000000, 13.000000, 10.000000, 1.000000, 264.000000, 352.000000, 1049.000000, 872.000000, 1130.000000, 727.000000, 12.000000, 21.000000, 20.000000, 15.000000, 8.000000, 0.000000, 440.000000, 488.000000, 786.000000, 745.000000, 593.000000, 1026.000000, 45.000000, 24.000000, 14.000000, 11.000000, 8.000000, 10.000000, 401.000000, 309.000000, 944.000000, 582.000000, 642.000000, 818.000000, 23.000000, 20.000000, 22.000000, 12.000000, 11.000000, 18.000000,
 88.000000, 180.000000, 600.000000, 631.000000, 602.000000, 647.000000, 2.000000, 9.000000, 0.000000, 6.000000, 2.000000, 7.000000, 243.000000, 497.000000, 691.000000, 602.000000, 651.000000, 1016.000000, 3.000000, 20.000000, 31.000000, 11.000000, 6.000000, 17.000000, 319.000000, 455.000000, 694.000000, 643.000000, 1014.000000, 727.000000, 34.000000, 30.000000, 21.000000, 17.000000, 16.000000, 8.000000, 305.000000, 551.000000, 712.000000, 706.000000, 801.000000, 926.000000, 26.000000, 32.000000, 31.000000, 10.000000, 12.000000, 15.000000, 284.000000, 546.000000, 692.000000, 766.000000, 915.000000, 746.000000, 35.000000, 34.000000, 21.000000, 13.000000, 13.000000, 14.000000, 258.000000, 488.000000, 559.000000, 808.000000, 1058.000000, 726.000000, 34.000000, 28.000000, 8.000000, 15.000000, 16.000000, 10.000000, 266.000000, 476.000000, 792.000000, 569.000000, 724.000000, 1086.000000, 9.000000, 28.000000, 31.000000, 8.000000, 16.000000, 18.000000, 292.000000, 348.000000, 725.000000, 480.000000, 748.000000, 928.000000, 6.000000, 30.000000, 24.000000, 15.000000, 9.000000, 16.000000, 317.000000, 409.000000, 844.000000, 554.000000, 720.000000, 1010.000000, 20.000000, 7.000000, 25.000000, 8.000000, 12.000000, 9.000000, 353.000000, 363.000000, 552.000000, 844.000000, 999.000000, 739.000000, 26.000000, 22.000000, 17.000000, 7.000000, 7.000000, 10.000000, 294.000000, 336.000000, 464.000000, 739.000000, 917.000000, 743.000000, 25.000000, 29.000000, 3.000000, 13.000000, 11.000000, 12.000000, 286.000000, 212.000000, 637.000000, 654.000000, 700.000000, 767.000000, 11.000000, 8.000000, 12.000000, 14.000000, 3.000000, 9.000000, 264.000000, 234.000000, 653.000000, 642.000000, 750.000000, 699.000000, 9.000000, 8.000000, 12.000000, 9.000000, 4.000000, 18.000000, 310.000000, 398.000000, 679.000000, 626.000000, 776.000000, 996.000000, 14.000000, 21.000000, 18.000000, 9.000000, 16.000000, 13.000000, 304.000000, 400.000000, 618.000000, 691.000000, 1000.000000, 772.000000, 17.000000, 27.000000, 13.000000, 12.000000, 17.000000, 12.000000, 390.000000, 334.000000, 678.000000, 966.000000, 1217.000000, 599.000000, 25.000000, 9.000000, 11.000000, 6.000000, 9.000000, 11.000000, 332.000000, 346.000000, 951.000000, 683.000000, 596.000000, 1222.000000, 8.000000, 6.000000, 23.000000, 10.000000, 9.000000, 7.000000, 221.000000, 381.000000, 533.000000, 498.000000, 571.000000, 658.000000, 14.000000, 34.000000, 11.000000, 17.000000, 16.000000, 15.000000,
 88.000000, 102.000000, 643.000000, 590.000000, 608.000000, 659.000000, 4.000000, 3.000000, 5.000000, 2.000000, 6.000000, 3.000000, 297.000000, 403.000000, 696.000000, 595.000000, 641.000000, 1020.000000, 1.000000, 24.000000, 36.000000, 11.000000, 8.000000, 17.000000, 367.000000, 507.000000, 715.000000, 600.000000, 1008.000000, 737.000000, 32.000000, 26.000000, 26.000000, 15.000000, 20.000000, 12.000000, 311.000000, 561.000000, 749.000000, 667.000000, 807.000000, 938.000000, 28.000000, 28.000000, 36.000000, 10.000000, 14.000000, 9.000000, 312.000000, 560.000000, 727.000000, 715.000000, 919.000000, 756.000000, 33.000000, 28.000000, 26.000000, 11.000000, 13.000000, 10.000000, 336.000000, 476.000000, 564.000000, 761.000000, 1052.000000, 730.000000, 32.000000, 24.000000, 13.000000, 15.000000, 16.000000, 10.000000, 336.000000, 504.000000, 797.000000, 516.000000, 722.000000, 1090.000000, 7.000000, 32.000000, 36.000000, 10.000000, 16.000000, 12.000000, 360.000000, 362.000000, 732.000000, 445.000000, 744.000000, 932.000000, 4.000000, 32.000000, 29.000000, 15.000000, 13.000000, 12.000000, 395.000000, 353.000000, 861.000000, 511.000000, 724.000000, 1014.000000, 20.000000, 9.000000, 28.000000, 10.000000, 8.000000, 7.000000, 399.000000, 381.000000, 605.000000, 845.000000, 983.000000, 763.000000, 24.000000, 26.000000, 22.000000, 3.000000, 9.000000, 10.000000, 348.000000, 340.000000, 477.000000, 692.000000, 905.000000, 745.000000, 23.000000, 31.000000, 8.000000, 9.000000, 15.000000, 16.000000, 282.000000, 218.000000, 690.000000, 629.000000, 700.000000, 771.000000, 13.000000, 10.000000, 9.000000, 10.000000, 7.000000, 11.000000, 274.000000, 194.000000, 692.000000, 599.000000, 748.000000, 703.000000, 11.000000, 10.000000, 11.000000, 9.000000, 8.000000, 14.000000, 350.000000, 426.000000, 682.000000, 571.000000, 768.000000, 998.000000, 12.000000, 25.000000, 21.000000, 11.000000, 20.000000, 9.000000, 350.000000, 424.000000, 629.000000, 664.000000, 992.000000, 774.000000, 15.000000, 23.000000, 18.000000, 8.000000, 19.000000, 12.000000, 410.000000, 382.000000, 727.000000, 933.000000, 1203.000000, 619.000000, 23.000000, 9.000000, 6.000000, 2.000000, 9.000000, 11.000000, 386.000000, 384.000000, 960.000000, 646.000000, 600.000000, 1226.000000, 10.000000, 10.000000, 28.000000, 12.000000, 9.000000, 3.000000, 277.000000, 391.000000, 580.000000, 485.000000, 605.000000, 686.000000, 12.000000, 36.000000, 16.000000, 15.000000, 12.000000, 11.000000,
 277.000000, 253.000000, 886.000000, 618.000000, 622.000000, 672.000000, 22.000000, 20.000000, 6.000000, 7.000000, 15.000000, 10.000000, 310.000000, 520.000000, 563.000000, 593.000000, 663.000000, 703.000000, 17.000000, 21.000000, 37.000000, 12.000000, 13.000000, 12.000000, 194.000000, 300.000000, 838.000000, 620.000000, 1060.000000, 634.000000, 18.000000, 15.000000, 27.000000, 16.000000, 1.000000, 3.000000, 356.000000, 384.000000, 858.000000, 707.000000, 855.000000, 789.000000, 20.000000, 31.000000, 37.000000, 9.000000, 11.000000, 12.000000, 369.000000, 419.000000, 830.000000, 763.000000, 971.000000, 603.000000, 15.000000, 31.000000, 27.000000, 12.000000, 12.000000, 9.000000, 187.000000, 377.000000, 715.000000, 797.000000, 1102.000000, 587.000000, 14.000000, 19.000000, 14.000000, 14.000000, 5.000000, 1.000000, 345.000000, 421.000000, 676.000000, 562.000000, 742.000000, 751.000000, 11.000000, 29.000000, 37.000000, 9.000000, 5.000000, 7.000000, 303.000000, 421.000000, 653.000000, 457.000000, 758.000000, 617.000000, 14.000000, 19.000000, 30.000000, 16.000000, 10.000000, 17.000000, 534.000000, 438.000000, 678.000000, 545.000000, 756.000000, 723.000000, 36.000000, 20.000000, 29.000000, 9.000000, 11.000000, 18.000000, 260.000000, 196.000000, 890.000000, 847.000000, 1025.000000, 756.000000, 6.000000, 17.000000, 23.000000, 8.000000, 12.000000, 1.000000, 331.000000, 189.000000, 736.000000, 724.000000, 945.000000, 586.000000, 5.000000, 18.000000, 9.000000, 14.000000, 6.000000, 7.000000, 217.000000, 191.000000, 975.000000, 645.000000, 716.000000, 620.000000, 13.000000, 21.000000, 10.000000, 15.000000, 14.000000, 2.000000, 355.000000, 335.000000, 955.000000, 633.000000, 784.000000, 584.000000, 15.000000, 17.000000, 12.000000, 10.000000, 13.000000, 15.000000, 341.000000, 309.000000, 521.000000, 625.000000, 786.000000, 681.000000, 6.000000, 22.000000, 22.000000, 10.000000, 1.000000, 8.000000, 125.000000, 277.000000, 714.000000, 670.000000, 1010.000000, 609.000000, 3.000000, 18.000000, 19.000000, 13.000000, 0.000000, 1.000000, 227.000000, 171.000000, 958.000000, 939.000000, 1237.000000, 668.000000, 5.000000, 8.000000, 5.000000, 7.000000, 14.000000, 0.000000, 573.000000, 515.000000, 657.000000, 682.000000, 614.000000, 901.000000, 28.000000, 21.000000, 29.000000, 11.000000, 14.000000, 10.000000, 324.000000, 380.000000, 885.000000, 493.000000, 637.000000, 735.000000, 18.000000, 25.000000, 17.000000, 16.000000, 13.000000, 18.000000,
 231.000000, 465.000000, 948.000000, 632.000000, 585.000000, 660.000000, 35.000000, 34.000000, 4.000000, 10.000000, 10.000000, 17.000000, 244.000000, 382.000000, 703.000000, 587.000000, 618.000000, 835.000000, 30.000000, 19.000000, 35.000000, 11.000000, 8.000000, 5.000000, 222.000000, 228.000000, 784.000000, 606.000000, 925.000000, 664.000000, 1.000000, 13.000000, 25.000000, 11.000000, 4.000000, 4.000000, 462.000000, 240.000000, 976.000000, 723.000000, 712.000000, 839.000000, 27.000000, 13.000000, 35.000000, 14.000000, 16.000000, 7.000000, 415.000000, 283.000000, 948.000000, 765.000000, 828.000000, 645.000000, 16.000000, 9.000000, 25.000000, 15.000000, 17.000000, 12.000000, 285.000000, 371.000000, 799.000000, 785.000000, 975.000000, 597.000000, 17.000000, 15.000000, 12.000000, 9.000000, 10.000000, 6.000000, 305.000000, 469.000000, 856.000000, 554.000000, 717.000000, 903.000000, 24.000000, 11.000000, 35.000000, 16.000000, 10.000000, 2.000000, 311.000000, 605.000000, 813.000000, 443.000000, 749.000000, 755.000000, 27.000000, 21.000000, 28.000000, 7.000000, 11.000000, 10.000000, 446.000000, 438.000000, 836.000000, 559.000000, 663.000000, 835.000000, 17.000000, 34.000000, 29.000000, 14.000000, 16.000000, 11.000000, 330.000000, 296.000000, 942.000000, 819.000000, 932.000000, 768.000000, 17.000000, 17.000000, 21.000000, 9.000000, 17.000000, 6.000000, 219.000000, 343.000000, 788.000000, 712.000000, 854.000000, 644.000000, 14.000000, 22.000000, 7.000000, 3.000000, 11.000000, 0.000000, 281.000000, 387.000000, 1027.000000, 655.000000, 705.000000, 674.000000, 26.000000, 33.000000, 8.000000, 2.000000, 9.000000, 5.000000, 409.000000, 511.000000, 937.000000, 647.000000, 711.000000, 580.000000, 28.000000, 35.000000, 10.000000, 13.000000, 8.000000, 8.000000, 261.000000, 491.000000, 675.000000, 621.000000, 747.000000, 829.000000, 19.000000, 18.000000, 22.000000, 15.000000, 4.000000, 13.000000, 239.000000, 469.000000, 816.000000, 660.000000, 965.000000, 641.000000, 16.000000, 16.000000, 17.000000, 8.000000, 5.000000, 8.000000, 437.000000, 373.000000, 1034.000000, 929.000000, 1130.000000, 648.000000, 14.000000, 34.000000, 7.000000, 10.000000, 19.000000, 7.000000, 489.000000, 705.000000, 919.000000, 696.000000, 569.000000, 1051.000000, 41.000000, 33.000000, 27.000000, 16.000000, 19.000000, 13.000000, 294.000000, 430.000000, 885.000000, 493.000000, 542.000000, 713.000000, 19.000000, 5.000000, 15.000000, 11.000000, 16.000000, 11.000000,

};

PI_CL_L1 int y_test[N_TEST] = {

 4, 0, 6, 7, 4, 3, 0, 0, 9, 1,

};

#endif 
