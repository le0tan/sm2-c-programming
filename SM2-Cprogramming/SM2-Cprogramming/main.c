//
//  main.c
//  SM2-Cprogramming
//
//  Created by Leo Tan on 23/08/2017.
//  Copyright © 2017 ltscript. All rights reserved.
//

//
// Created by Leo Tan on 3/11/17.
//

#include <stdio.h>

int main(){
    
    int a[2][2][2]={1,2,3,4,5,6,7,8};
    int* ptr = a;
    
    for(int i=1;i<=8;i++){
        printf("%d ",*ptr);
        ptr++;
    }
    
    return 0;
}


//#include <stdio.h>
//
//#define x 6
//
//
//void swap(int* a,int* b){
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//    return;
//}
//
//
//int main(){
//
//    //Used as control variable in for-loops
//    int i,j,k,l,m;
//    //mi/j/j/l represents the indices of the smallest "neighbourhood" "up to now"
//    //so does mmi/j/k/l
//    //mi is used in the loop of traversing every element of the hyper-cube - the loop where we visit its neighbour in every dimension
//    //mmi is used in the heap restortion step
//    //ci/j/k/l represents the "current" element awaiting to be put into the right place during the process of heap restortion
//    int mi,mj,mk,ml,mmi,mmj,mmk,mml,ci,cj,ck,cl;
//    int exchanged = 0;
//    int cksm1 = 0, cksm2 = 0, checked = 1, last = -1;
//
//    int G[x][x][x][x]={9929,4821,5786,5339,8535,3314,7274,8209,9324,5502,3034,6227,8891,9327,8095,113,6312,1263,9834,1823,2948,2239,3854,9558,7087,6323,1065,3656,6059,4041,4385,177,1300,8255,5072,4046,
//        250,2358,1451,2588,2332,3822,5120,1147,8385,1074,9953,2750,5354,5839,3755,3957,5159,9604,8044,4501,1594,38,4736,5147,9760,5421,4275,6070,8885,8210,2155,3588,6248,910,125,6461,
//        8434,3437,4127,4671,5493,5898,5330,7151,4819,6183,4563,8843,419,1402,937,4990,6435,2479,6366,1723,8383,5926,8875,1369,6359,3606,4822,8475,9372,3572,4526,4740,7910,5004,4380,9012,
//        6643,7607,5155,5212,3193,6698,5082,3773,7145,5930,4145,7482,7632,3415,4918,7083,6918,145,7843,2793,8106,4156,3747,2745,2325,6340,403,3941,3784,9582,4068,3114,5261,6589,7864,1797,
//        8190,837,3198,7091,4628,9048,8097,2491,9230,7170,7633,9718,9348,8310,2772,2983,7664,6548,7565,5367,2539,4244,9400,6786,734,5805,3740,3991,9473,5157,7727,8731,7733,591,3989,5922,
//        8743,2612,9198,3512,5199,5625,1255,6421,9164,7860,2534,8615,7429,7419,8730,9511,3506,6754,6973,6558,9764,2514,6684,8144,5644,7894,9402,4023,855,2366,522,6182,835,2872,8234,9566,
//        4037,8368,5769,9375,5218,268,9178,9531,9698,9399,1021,1853,3309,9326,1104,6793,3243,366,9898,2321,9659,3765,8013,2615,7433,9445,5598,7843,3262,1771,6010,547,6940,7441,8668,8986,
//        6684,5861,1892,8610,7837,6300,4134,4425,4342,9839,9835,7519,5018,9718,4068,1750,5698,6969,3431,3207,1754,6268,6804,648,1164,796,1557,4639,49,6364,9215,3697,7571,5321,1274,6409,
//        8650,2677,7237,5534,4229,3937,4539,1941,9861,4371,5631,8333,5787,1883,4553,1439,6506,8752,5920,2337,5048,4971,5640,5723,6357,603,4661,8151,3897,4888,32,2978,7907,4817,3253,6719,
//        2958,4286,693,2790,5929,696,3919,7032,1573,6701,9592,754,3527,179,9006,5392,4503,253,357,9664,3678,7718,3413,1054,1940,1692,4783,2301,5225,1804,4876,117,8722,3143,4088,177,
//        9875,6794,9335,2811,1518,2628,345,3528,3448,3008,3527,1254,3570,2448,397,2222,3731,1770,3259,3559,7969,4637,6748,4595,6474,5857,4679,8600,7771,9266,7759,1481,6201,7772,6181,7370,
//        1719,3138,458,4508,1157,7711,4293,9886,5395,8902,7615,6591,9176,6923,1550,5049,4235,3654,7592,6759,8869,8658,2474,8417,174,6792,5125,709,3068,7791,2695,9064,476,3172,2193,6942,
//        1341,998,8471,5878,7623,5764,4041,294,6095,9803,1979,2324,4729,4615,6113,2989,727,9901,5314,9067,2095,7403,7639,7322,1005,7110,5824,5251,4843,5453,653,2755,4849,382,4273,2932,
//        9223,3552,3892,6124,1356,7398,689,7838,6974,7827,2341,3584,5998,3423,7688,4722,2010,5591,5981,4615,8936,2128,3325,5179,7783,748,6615,3102,3074,9663,3984,937,6001,8953,7407,1067,
//        1806,8008,4069,5586,9346,8223,8191,3823,2235,5687,1243,1461,2449,3700,7288,575,425,429,8482,311,2342,6090,8841,7542,619,3069,1018,4052,3077,1524,3092,9588,3429,2917,2007,5202,
//        8179,3252,4944,2944,362,9164,7841,7747,8995,403,5616,899,6726,7341,1956,5303,9774,7853,1402,3460,3929,3833,5683,3557,2758,2276,5959,3247,2992,2503,1329,1307,2011,5147,6375,5776,
//        1128,1230,4399,6438,3616,1555,4652,5725,4141,773,4578,6376,4832,8056,2845,7373,4104,3489,919,2791,7372,8404,7800,5290,9715,2958,4042,8921,7769,5180,192,8077,6852,8995,6322,9200,
//        719,5419,139,3200,6939,2316,5581,5652,3112,1972,9853,1665,1081,4389,5228,2920,8059,1340,7394,5973,8543,2202,7736,1234,2160,7025,57,8990,5305,4365,5906,9836,9737,8220,8331,9211,
//        2659,6173,3327,6426,3730,4677,3193,567,7159,5691,9160,4270,2513,6047,4506,3923,4091,96,1142,4948,1642,973,6288,3764,2314,9430,5723,6609,3110,718,4482,6335,8972,8058,8946,7404,
//        5021,2954,7358,6696,2887,8182,6337,5556,272,2842,4007,9541,8200,6811,589,2131,8028,5175,3909,7419,1164,4018,7024,4121,2247,6640,6727,1816,7337,3146,9933,7035,3282,8268,9319,5205,
//        6796,2965,8096,1118,9443,933,740,4156,4058,4526,3104,9740,4300,6908,6919,3573,2804,3866,8984,8282,125,7667,1518,1291,9602,8064,8226,656,9431,801,7727,8148,6649,5968,5828,3422,
//        1486,3072,6462,2343,464,6369,7846,4085,9869,3367,4303,5825,4788,8345,1425,9405,58,3017,9818,3149,7793,4051,4331,4205,6727,129,7774,5617,6816,2748,1338,2294,64,2137,6457,5873,
//        6093,1796,7795,4661,839,1263,9621,3865,6702,1259,1845,2935,6220,6514,6668,7952,833,5753,490,8281,8900,2978,9403,8042,1263,4275,6117,8383,3501,6031,8388,4232,4621,9003,6239,3752,
//        7390,6403,8020,5706,1253,3663,529,9891,2656,5938,6464,1067,6558,2196,2658,674,362,3493,1624,5645,1548,370,9312,1955,8188,9977,1531,7084,2179,2766,6425,5628,2392,9268,6463,6569,
//        5809,1326,6613,7507,1743,2451,5046,8058,4524,6835,9010,9645,6983,2201,8963,1247,4631,5469,6981,203,7038,9336,8221,8441,1864,9036,1858,7574,801,5324,3129,903,2396,7761,5440,3043,
//        620,4643,9370,9123,2709,1092,5700,2171,5720,2100,6414,2240,544,8302,4929,3302,6300,8534,1235,1717,672,5413,5519,6300,2187,4840,3942,6318,8746,7322,3179,1743,2316,2725,6925,1868,
//        9306,317,6243,449,338,8687,6895,4228,9905,4965,4931,7592,8715,5192,874,1306,7050,1264,5374,1595,9651,1137,4391,3588,2478,1314,6244,5645,2623,9313,4887,6198,6312,2325,9482,1275,
//        8091,598,6701,8450,5136,2274,8309,7455,4640,8903,2388,2152,1804,9376,3685,8879,5121,7724,7890,2129,3115,6512,3236,9586,678,886,8640,3693,5619,8895,2781,1533,4673,8250,2909,7391,
//        2002,747,3471,4216,6873,9733,2647,5549,1,3750,428,6647,5665,285,3094,6897,2301,6155,5171,9794,5155,7652,2828,2049,6302,2378,8391,4291,3399,4832,4010,7194,8426,7174,776,7180,
//        9861,5637,1737,856,8798,9839,4132,9839,2376,4068,3680,3615,4896,1201,2387,9746,3961,5083,7457,3489,4674,4500,2347,4058,2776,4200,1010,3116,197,1257,5401,8435,6426,598,4805,7734,
//        3746,5552,4238,9715,3783,3047,6546,9761,5782,8691,6960,1087,4264,6850,9909,4469,9612,9582,9093,8595,1038,5169,9133,4521,4473,6498,2510,8351,1221,9571,6405,4865,5371,660,839,2522,
//        350,8763,8529,2817,1358,7496,7765,3281,2291,992,3541,5654,2235,8075,1610,3099,6691,9710,7562,4187,9914,5520,5841,8428,951,6696,3372,2752,7944,9267,2092,7188,739,9162,7750,791,
//        4066,8692,64,5905,315,6463,7711,147,792,8923,4119,6804,6296,7784,263,1264,689,3900,7261,3463,9272,9492,530,6307,6507,9784,9995,2908,6958,9897,9729,7607,9409,3707,8997,1851,
//        7143,2788,4416,2698,2018,1339,5191,129,391,6389,8884,8467,633,3346,9909,1681,1604,5653,5543,1869,3861,2182,2815,1550,3929,8898,8418,72,6168,7083,9822,2101,8921,407,8087,4988,
//        7598,7842,2865,8463,9068,2446,7138,7145,2535,333,9879,7312,3420,1646,7365,2765,9287,5502,4916,6155,8691,332,1803,8724,3588,5884,6227,8838,6425,7587,9830,9362,4270,1851,5413,8042,
//        6153,289,253,4818,9910,4648,1530,339,5142,7385,1937,3584,6023,4434,5677,1670,8359,4373,4690,5413,8642,4509,7109,2774,9260,7155,7111,7774,8174,4365,9492,282,5843,1476,5733,8561};
//    for(i=0;i<x;i++)
//        for(j=0;j<x;j++)
//            for(k=0;k<x;k++)
//                for(l=0;l<x;l++)
//                    cksm1+=G[i][j][k][l];
//
//    for(i=0;i<x;i++){
//        for(j=0;j<x;j++){
//            for(k=0;k<x;k++){
//                for(l=x-1;l>=0;l--){
//                    for(m=0;m<l;m++){
//                        if(G[i][j][k][m]>G[i][j][k][m+1]){
//                            swap(&G[i][j][k][m],&G[i][j][k][m+1]);
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    for(i=0;i<x;i++){
//        for(j=0;j<x;j++){
//            for(k=0;k<x;k++){
//                for(l=x-1;l>=0;l--){
//                    for(m=0;m<l;m++){
//                        if(G[i][j][m][k]>G[i][j][m+1][k]){
//                            swap(&G[i][j][m][k],&G[i][j][m+1][k]);
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    for(i=0;i<x;i++){
//        for(j=0;j<x;j++){
//            for(k=0;k<x;k++){
//                for(l=x-1;l>=0;l--){
//                    for(m=0;m<l;m++){
//                        if(G[i][m][j][k]>G[i][m+1][j][k]){
//                            swap(&G[i][m][j][k],&G[i][m+1][j][k]);
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    for(i=0;i<x;i++){
//        for(j=0;j<x;j++){
//            for(k=0;k<x;k++){
//                for(l=x-1;l>=0;l--){
//                    for(m=0;m<l;m++){
//                        if(G[m][i][j][k]>G[m+1][i][j][k]){
//                            swap(&G[m][i][j][k],&G[m+1][i][j][k]);
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    //    for(i=0;i<x;i++){
//    //        for(j=0;j<x;j++){
//    //            for(k=0;k<x;k++) {
//    //                for (l = 0; l < x; l++)
//    //                    printf("%d ", G[i][j][k][l]);
//    //                printf("\n");
//    //            }
//    //            printf("\n");
//    //        }
//    //        printf("\n");
//    //    }
//    //    printf("\n");
//
//    for(i=0;i<x;i++){
//        for(j=0;j<x;j++){
//            for(k=0;k<x;k++){
//                for(l=0;l<x;l++){
//                    mi = i; mj = j; mk = k; ml = l;
//                    if(i+1<x && G[i+1][0][0][0]<G[i][j][k][l]){
//                        mi = i+1; mj = 0; mk = 0; ml = 0; exchanged = 1;
//                    }
//                    if(j+1<x && G[i][j+1][0][0]<G[i][j][k][l] && G[i][j+1][0][0]<G[mi][mj][mk][ml]){
//                        mi = i; mj = j+1; mk = 0; ml = 0; exchanged = 1;
//                    }
//                    if(k+1<x && G[i][j][k+1][0]<G[i][j][k][l] && G[i][j][k+1][0]<G[mi][mj][mk][ml]){
//                        mi = i; mj = j; mk = k+1; ml = 0; exchanged = 1;
//                    }
//                    if(exchanged){
//                        swap(&G[i][j][k][l],&G[mi][mj][mk][ml]);
//                        mmi = ci = mi; mmj = cj = mj; mmk = ck = mk; mml = cl = ml;
//                        do{
//                            exchanged = 0;
//                            if(ci+1<x && G[ci+1][0][0][0]<G[ci][cj][ck][cl]){
//                                mmi = ci+1; mmj = 0; mmk = 0; mml = 0; exchanged = 1;
//                            }
//                            if(cj+1<x && G[ci][cj+1][0][0]<G[ci][cj][ck][cl] && G[ci][cj+1][0][0]<G[mmi][mmj][mmk][mml]){
//                                mmi = ci; mmj = cj+1; mmk = 0; mml = 0; exchanged = 1;
//                            }
//                            if(ck+1<x && G[ci][cj][ck+1][0]<G[ci][cj][ck][cl] && G[ci][cj][ck+1][0]<G[mmi][mmj][mmk][mml]){
//                                mmi = ci; mmj = cj; mmk = ck+1; mml = 0; exchanged = 1;
//                            }
//                            if(cl+1<x && G[ci][cj][ck][cl+1]<G[ci][cj][ck][cl] && G[ci][cj][ck][cl+1]<G[mmi][mmj][mmk][mml]){
//                                mmi = ci; mmj = cj; mmk = ck; mml = cl+1; exchanged = 1;
//                            }
//                            if(exchanged){
//                                swap(&G[ci][cj][ck][cl],&G[mmi][mmj][mmk][mml]);
//                                ci = mmi; cj = mmj; ck = mmk; cl = mml;
//                            }
//                        } while(exchanged);
//                    }
//                }
//            }
//        }
//    }
//
//    for(i=0;i<x;i++)
//        for(j=0;j<x;j++)
//            for(k=0;k<x;k++)
//                for(l=0;l<x;l++){
//                    if(G[i][j][k][l]<last){
//                        checked = 0;
//                        goto END;
//                    }
//                    last = G[i][j][k][l];
//                    cksm2+=G[i][j][k][l];
//                }
//
//END:
//    if(cksm1==cksm2 && checked) printf("sorted!");
//    else printf("not sorted!");
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int main(){
//    int k = 4;
//    srand(47);
//    for(int i=1;i<=k*k*k;i++){
//        printf("%d,",rand()%10000);
//        if(i%(k)==0) printf("\n");
//    }
//    return 0;
//}


//int a,letter[8][8] =
//{
//    {6, 6, 6, 6, 6, 6, 6, 6},
//    6, 2, 2, 2, 2, 2, 2, 6,
//    6, 3, 1, 0, 1, 1, 2, 7,
//    6, 6, 5, 0, 1, 5, 6, 6,
//    6, 6, 5, 3, 3, 5, 6, 7,
//    7, 6, 5, 3, 2, 6, 6, 7,
//    7, 6, 6, 2, 2, 5, 6, 7,
//    7, 7, 7, 7, 7, 7, 7, 7
//};

//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#define MAXN 100000
//#define SEED 47
//
//int global_count = 0;
//
//void swap(int* a,int* b){
//    int temp = *b; *b = *a; *a = temp; return;
//}
//
//void sift_up(int* A, int idx, int len){
//    int largest_son;
//    if(idx*2+1>len) {
//        global_count++;
//        return;
//    }
//    if(idx*2+2>len) {
//        global_count++;
//        largest_son = idx*2+1;
//    }
//    else if(A[idx*2+1]>A[idx*2+2]) {
//        global_count++;
//        largest_son = idx*2+1;
//    }
//    else {
//        global_count++;
//        largest_son = idx*2+2;
//    }
//    if(A[largest_son]>A[idx]){
//        global_count++;
//        swap(&A[idx],&A[largest_son]);
//        sift_up(A,largest_son,len);
//    } else return;
//}
//
//void build_heap(int *A, int len){
//    int i;
//    for(i=len;i>=0;i--) sift_up(A,i,len);
//    return;
//}
//
//void heap_sort(int *A, int len){
//    int i,last = len;
//    build_heap(A, len);
//    for(i=0;i<len;i++){
//        swap(&A[0],&A[last--]);
//        sift_up(A, 0, last);
//    }
//    return;
//}
//
//int main(){
//    int a[MAXN];
//    int i,j,len = sizeof(a)/sizeof(int)-1;
//    int size,avg=0;
//
//    srand(SEED);
//
//    for(size=1;size<MAXN;size++){
//        len = size-1;
//        for(j=0;j<10;j++){
//            for(i=0;i<MAXN;i++) a[i] = rand();
//            heap_sort(a,len);
//            printf("Operation counts: \t%d\n",global_count);
//            printf("n*log(n) equals to: \t%d\n",(int)(len*log(len)/log(2.0)));
//            global_count=0;
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int a(int x){
//    if(x>0) return 0;
//    printf("233");
//}
//
//int main(void){
//    
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#define SEED 31
//#define b 2
//
//
//int main()
//{
//    int a;
//    scanf("%d",&a);
//    printf("\n%d",a);
//    
//    return 0;
//}

//#include <stdio.h>
//
//int main(){
//    int a=2;
//    return 0;
//}

//int main(){
//    
//    int a,b;
//    char c='s';
//    b = scanf("%d%c",&a,&c);
//    scanf("%c",&c);
//    scanf("%d",&a);
//    printf("\n%d %c %d",a,c,b);
//    
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//#define tolerance 0.00001
//#define rounds 10000
//#define x 1
//
//int main(){
//    int cnt = 1;
//    double term=.5,sum=1.5;
//    while((term>=tolerance || term<=-tolerance)&&cnt<=rounds){
//        cnt++;
//        term=term*(-1.0)*(2*cnt-3)/(2*cnt)*x;
//        sum+=term;
//    }
//    printf("%lf\n",sum);
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int check_prime(int a){
//    int i;
//    if(a<=0) return 0;
//    for(i=2;i<=sqrt(a);i++){
//        if(a%i == 0) return 0;
//    }
//    return 1;
//}
//
//int main(){
//    int i;
//    for(i=1;i<=31;i++)
//        if(check_prime((1<<i)-1))
//            printf("%d\n",(1<<i)-1);
//    return 0;
//}

//#include <stdio.h>
//
//
//int main(){
//    int a,b,c,sum=0;
//    
//    scanf("%d",&a);
//    c=a;
//    while(a>0){
//        b=a%10;
//        a/=10;
//        sum+=b*b*b;
//    }
//    if(sum==c) printf("yes");
//    else printf("no");
//    
//    return 0;
//}

////lab4 a5
//#include <stdio.h>
//#include <stdlib.h>
//#define SEED 31
//int main()
//{
//    srand (SEED);
//    int i,n=0;
//    double x,y;
//    for(i=0;i<100;i++)
//    {
//        x=rand()/RAND_MAX*1.0*3+2;
//        y=rand()/RAND_MAX*1.0*25;
//        if (y<x*x)
//            n++;
//    }
//    printf("%lf",25*3*n/100.0);
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//
//int main(void){
//    int a=1;
//    int b = -a++;
//    printf("%d",b);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#define f(x) (exp(2*(x))-(x)-6)
//#define fpr(x) (2*exp(2*(x))-1)
//#define tolarance 0.0000001
//#define round 10000
//
//int main(void){
//    
//    double x1 = 0.25;
//    int cnt = 0;
//    while((f(x1)>=tolarance||f(x1)<=tolarance)&&cnt<=round){
//        cnt++;
//        x1=x1-(f(x1)/fpr(x1));
//    }
//    printf("%.5lf\n",x1);
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main(){
//    printf("%d",'a');
//    return 0;
//}

//int main()
//{
//    float x0=0.25,x1,y0,y_;
//    do
//    {
//        y0=exp(2*x0)-x0-6;
//        y_=2*exp(2*x0)-1;
//        x1=x0-y0/y_;
//        x0=x1;
//    }
//    while(y0>=0.0001||y0<=-0.0001);
//    printf("%f",x0);
//}

//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//
//int main(void){
//    srand(47);
//    int i,cnt=0;
//    double x,y,f1,f2,area;
//    for(i=1;i<=10000;i++){
//        x = rand()*1.0/RAND_MAX*3-2.0;
//        y = rand()*1.0/RAND_MAX*7;
//        printf("x = %.2lf, y = %.2lf\n",x,y);
//        f1 = 7.0-x*x;
//        f2 = exp(x);
//        printf("f1 = %.2lf, f2 = %.2lf\n",f1,f2);
//        if(y>=f2 && y<=f1) cnt++;
//    }
//    area = 3.0*7.0*cnt/10000;
//    printf("%.5lf",area);
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//#define tor 0.0001
//
//int main(void){
//    double term=-1.0,sum=0.0;
//    int cnt=0;
//    while (fabs(term*0.5/++cnt)>=tor) {
//        term = term*0.5*(-1);
//        sum+=term/cnt;
//    }
//    printf("%.4lf\n",sum);
//    return 0;
//}


//#include <stdio.h>
//
//
//int main(void){
//    int flag = 0;
//    char a;
//    while(scanf("%c",&a)){
//        if(a==' ')
//            if(flag) continue;
//            else{
//                flag = 1;
//                printf(" ");
//            }
//        else{
//            if(flag) flag = 0;
//            if(a=='\n') {
//                printf("\n");
//                break;
//            }
//            else printf("%c",a);
//        }
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#define SEED 129387
//#define ROUND 10000
//
//int dice(){
//    int ans = rand()%100;
//    if(ans<=20) return 1;
//    else if(ans>20&&ans<=40) return 2;
//    else if(ans>40&&ans<=45) return 3;
//    else if(ans>45&&ans<=50) return 4;
//    else if(ans>50&&ans<=80) return 5;
//    else return 6;
//}
//
//int main(){
//    srand(SEED);
//    int i,bet=0,exb=0;
//    for(i=1;i<=ROUND;i++){
//        bet+=2; exb+=2;
//        switch(dice()){
//            case 1:{
//                exb-=2;
//                break;
//            }
//            case 2:{
//                exb-=2;
//                break;
//            }
//            case 3:{
//                break;
//            }
//            case 4:{
//                break;
//            }
//            case 5:{
//                exb+=1;
//                break;
//            }
//            case 6:{
//                exb+=2;
//                break;
//            }
//            default: break;
//        }
//    }
//    double out = (double)(bet-exb)/(double)bet;
//    printf("The House Advantage = %lf \n",out*100);
//    return 0;
//}





//#include <stdio.h>
//
//int a=0;
//
//void change(int a){
//    a = a+1;
//}
//
//int main(void){
//    change(a);
//    a+=3;
//    printf("a=%d",a);
//    return 0;
//}



//#include <stdio.h>
//
//int main(void){
//    int a =3;
//    switch(a ){
//        default:
//            printf("233");
//        case 1:
//            printf("666");
//    }
//    return 0;
//}
//


//#include<stdio.h>
//#include<math.h>
//#define f(x)(37-(x)*(x)*(x)*(x)*(x))//(pow(37,1.0/5)-x)
//#define fpr(x)(-5*(x)*(x)*(x)*(x))
//#define rounds 100
//#define tol 0.000001
//int main(void)
//{
//    double x1,x2,a;
//    int i;
//    x1=0.49;
//    i=1;
//    x2=1.2;
//    
//    printf("%d",f(1));
//    
//    while((f(x1)<-tol||f(x1)>tol)&&i<=rounds)
//    {
//        printf("%d x=%.8lf f(x)=%.8lf\n", i,x1,f(x1));
//        a = x2;
//        x2 = x2-f(x2)*(x2-x1)/(f(x2)-f(x1));
//        x1=a;
//        i++;
//    }
//    printf("%d x=%.8lf f(x1)=%.8lf\n", i,x1,f(x1));
//    return 0;
//}


//#include <stdio.h>
//#include <math.h>
//#define E 2.7182818285
//#define INI 0.25
//
//double f(double x){
//    return pow(E,2*x)-x-6;
//}
//
//double G(double x0,double x1){
//    return (f(x1)-f(x0))/(x1-x0);
//}
//
//int main(){
//    double x0=0.25,x1=1.2,temp=2333.0,last=233.0;
//    int cnt=0;
//    while(fabs(last-temp)>=0.00000001){
//        if(fabs(x1-x0)<=0.0000000000001) break;
//        x0 = G(x1,x0);
//        temp = x1;
//        x1 = x1-(f(x1)/x0);
//        x0 = temp;
//        printf("Answer after %d iterations: %.8lf\n",++cnt,temp);
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//#define E 2.7182818285
//#define INI 0.25
//
//double d(double x){
//    return 2*pow(E,2*x)-1;
//}
//
//double f(double x){
//    return pow(E,2*x)-x-6;
//}
//
//int main(){
//    double ans;
//    double last = 1.0;
//    int iter = 0;
//    double init = INI;
//    ans = init;
//    while(fabs(ans-last)>=0.00000001){
//        last = ans;
//        iter++;
//        ans = ans - f(ans)/d(ans);
//        printf("Answer after %d iteration(s) = %.7lf\n",iter,ans);
//    }
//    return 0;
//}
//
