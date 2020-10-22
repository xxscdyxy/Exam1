// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// MPI_Send, MPI_Recv example. Communicates the number -1 from process 0
// to process 1.
//
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI acos(-1)

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);
    // Find out rank, size
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // We are assuming there are 4 processes for this task
    double h = PI / 99;
    int x_points = 99;
    double x[x_points + 1];
    double y[x_points + 1];

    if (world_rank == 0) {
        //set initial value
        x[0] = 0.0;
        x[1] = h;
        y[0] = 0.0;
        y[1] = sin(h);
        int i = 0;
        for (i = 1; i <= 23; i++)
        {
            y[i + 1] = cos(x[i]) * h + 2 * y[i] - y[i - 1];
            x[i + 1] = h * (i + 1);
        }
        // If we are rank 0, set the number to -1 and send it to process 1
        double number_1_to_2_1 = y[23];
        double number_1_to_2_2 = y[24];
        MPI_Send(
            /* data         = */ &number_1_to_2_1, &number_1_to_2_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* destination  = */ 1,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD);
        printf("Process 1 send number %lf%lf to process 2\n", number_1_to_2_1, number_1_to_2_2);

        MPI_Recv(
            /* data         = */ &number_2_to_1_1, &number_2_to_1_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* source       = */ 1,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD,
            /* status       = */ MPI_STATUS_IGNORE);
        printf("Process 1 received number %lf%lf from process 2\n", numbe_2_to_1_1, number_2_to_1_2);
        y[24] = cos(x[25]) * h + 2 * number_1_to_2_1 - number_1_to_2_2;

    }

    else if (world_rank == 1) {
        MPI_Recv(
            /* data         = */ &number_1_to_2_1, &number_1_to_2_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* source       = */ 0,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD,
            /* status       = */ MPI_STATUS_IGNORE);
        printf("Process 2 received number %lf%lf from process 1\n", number_1_to_2_1, number_1_to_2_2);
        x[23] = h * (23);
        x[24] = h * (24);
        y[23] = number_1_to_2_1;
        y[24] = number_1_to_2_2;
        int i = 0;
        for (i = 24; i <= 49; i++)
        {
            y[i + 1] = cos(x[i]) * h + 2 * y[i] - y[i - 1];
            x[i + 1] = h * (i + 1 + 25);
        }

        MPI_Recv(
            /* data         = */ &number_3_to_2_1, &number_3_to_2_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* source       = */ 2,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD,
            /* status       = */ MPI_STATUS_IGNORE);
        printf("Process 2 received number %lf%lf from process 3\n", number_3_to_2_1, number_3_to_2_2);
        y[49] = cos(x[50]) * h + 2 * number_3_to_2_1 - number_3_to_2_2;

        double number_2_to_1_1 = y[25];
        double number_2_to_1_2 = y[26];
        MPI_Send(
            /* data         = */ &number_2_to_1_1, &number_2_to_1_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* destination  = */ 0,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD);
        printf("Process 2 send number %lf%lf to process 1\n", number_2_to_1_1, number_2_to_1_2);

        double number_2_to_3_1 = y[48];
        double number_2_to_3_2 = y[49];
        MPI_Send(
            /* data         = */ &number_2_to_3_1, &number_2_to_3_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* destination  = */ 2,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD);
        printf("Process 2 send number %lf%lf to process 3\n", number_2_to_3_1, number_2_to_3_2);

    }
    else if (world_rank == 2) {
        MPI_Recv(
            /* data         = */ &number_2_to_3_1, &number_2_to_3_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* source       = */ 1,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD,
            /* status       = */ MPI_STATUS_IGNORE);
        printf("Process 3 received number %lf%lf from process 2\n", number_2_to_3_1, number_2_to_3_2);

        x[48] = h * (48);
        x[49] = h * (49);
        y[48] = number_2_to_3_1;
        y[49] = number_2_to_3_2;
        int i = 0;
        for (i = 49; i <= 74; i++)
        {
            y[i + 1] = cos(x[i]) * h + 2 * y[i] - y[i - 1];
            x[i + 1] = h * (i + 1 + 50);
        }

        MPI_Recv(
            /* data         = */ &number_4_to_3_1, &number_4_to_3_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* source       = */ 3,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD,
            /* status       = */ MPI_STATUS_IGNORE);
        printf("Process 3 received number %lf%lf from process 4\n", number_4_to_3_1, number_4_to_3_2);
        y[74] = cos(x[75]) * h + 2 * number_4_to_3_1 - number_4_to_3_2;

        double number_3_to_2_1 = y[50];
        double number_3_to_2_2 = y[51];
        MPI_Send(
            /* data         = */ &number_3_to_2_1, &number_3_to_2_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* destination  = */ 1,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD);
        printf("Process 3 send number %lf%lf to process 2\n", number_3_to_2_1, number_3_to_2_2);

        double number_3_to_4_1 = y[73];
        double number_3_to_4_2 = y[74];
        MPI_Send(
            /* data         = */ &number_3_to_4_1, &number_3_to_4_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* destination  = */ 3,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD);
        printf("Process 3 send number %lf%lf to process 4\n", number_3_to_4_1, number_3_to_4_2);

    }
    else if (world_rank == 3) {
        MPI_Recv(
            /* data         = */ &number_3_to_4_1, &number_3_to_4_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* source       = */ 2,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD,
            /* status       = */ MPI_STATUS_IGNORE);
        printf("Process 4 received number %lf%lf from process 3\n", number_3_to_4_1, number_3_to_4_2);

        x[73] = h * (73);
        x[74] = h * (74);
        y[73] = number_3_to_4_1;
        y[74] = number_3_to_4_2;
        int i = 0;
        for (i = 74; i <= 99; i++)
        {
            y[i + 1] = cos(x[i]) * h + 2 * y[i] - y[i - 1];
            x[i + 1] = h * (i + 1 + 75);
        }

        double number_4_to_3_1 = y[75];
        double number_4_to_3_2 = y[76];
        MPI_Send(
            /* data         = */ &number_4_to_3_1, &number_4_to_3_2,
            /* count        = */ 2,
            /* datatype     = */ MPI_DOUBLE,
            /* destination  = */ 2,
            /* tag          = */ 0,
            /* communicator = */ MPI_COMM_WORLD);
        printf("Process 4 send number %lf%lf to process 3\n", number_4_to_3_1, number_4_to_3_2);


    }
    MPI_Finalize();
}
