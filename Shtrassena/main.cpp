#include <cstdio>
#include <cstdlib>

int* MlplyMatrix(int* aMtx1, int* aMtx2, int MSize);

int main()
{
    int MSize = 0;
    FILE* tmp = fopen("input.txt", "r");
    fscanf(tmp, "%d", &MSize);

    int* MatrixA = (int*)calloc( ((MSize + MSize % 2)*(MSize + MSize % 2)), sizeof(int) );
    int* TmpMatrix = MatrixA;

    for(int i = 0; i < MSize; ++i)
        {
        for(int j = 0; j < MSize; ++j)
            {
            fscanf(tmp, "%d ", TmpMatrix);
            ++TmpMatrix;
            }

        if(MSize%2)
            {
            ++TmpMatrix;
            }
        }

    int* MatrixB = (int*)calloc( ((MSize + MSize % 2)*(MSize + MSize % 2)), sizeof(int) );
    TmpMatrix = MatrixB;
    for(int i = 0; i < MSize; ++i)
        {
        for(int j = 0; j < MSize; ++j)
            {
            fscanf(tmp, "%d ", TmpMatrix);
            ++TmpMatrix;
            }

        if(MSize%2)
            {
            ++TmpMatrix;
            }
        }

    int* MatrixC = MlplyMatrix(MatrixA, MatrixB, MSize);

    fclose(tmp);
    tmp = fopen("output.txt", "w");
    for(int i = 0; i < MSize; ++i)
        {
        for(int j = 0; j < MSize; ++j)
            {
            fprintf(tmp, "%d ", *MatrixC);
            ++MatrixC;
            }
        fprintf(tmp, "\n");
        }

    fclose(tmp);
    free(MatrixA);
    free(MatrixB);
    free(MatrixC);
    return 0;
}

int* MlplyMatrix(int* aMtx1, int *aMtx2, int MSize)
    {
    MSize = MSize + MSize % 2;
    int* AnsMatrix = (int*)calloc( (MSize*MSize), sizeof(int));
    int* AnsTmp = AnsMatrix;
    if(MSize == 2)
        {
        *AnsMatrix       = *(aMtx1) * (*(aMtx2)) + *(aMtx1 + 1) * (*(aMtx2 + 2));
        *(AnsMatrix + 1) = *(aMtx1) * (*(aMtx2 + 1)) + *(aMtx1 + 1) * (*(aMtx2 + 3));
        *(AnsMatrix + 2) = *(aMtx1 + 1) * (*(aMtx2)) + *(aMtx1 + 3) * (*(aMtx2 + 2));
        *(AnsMatrix + 3) = *(aMtx1 + 1) * (*(aMtx2 + 1)) + *(aMtx1 + 3) * (*(aMtx2 + 3));
        } else
        {
        int* tmp1 = (int*)calloc((MSize/2*MSize/2), sizeof(int));
        int* tmp2 = (int*)calloc((MSize/2*MSize/2), sizeof(int));
        for(int i = 0; i < (MSize/2); ++i)
            for(int j = 0; j < (MSize/2); ++j)
            {
            *(tmp1 + i*MSize/2 + j) = *(aMtx1 + i*MSize + j) + *(aMtx1 + MSize*MSize/2 + MSize/2 + i*MSize + j);
            *(tmp2 + i*MSize/2 + j) = *(aMtx2 + i*MSize + j) + *(aMtx2 + MSize*MSize/2 + MSize/2 + i*MSize + j);
            }
        int* p1 = MlplyMatrix(tmp1, tmp2, MSize/2);
        for(int i = 0; i < (MSize/2); ++i)
            for(int j = 0; j < (MSize/2); ++j)
            {
            *(tmp1 + i*MSize/2 + j) = *(aMtx1 + MSize*MSize/2 + i*MSize + j) + *(aMtx1 + MSize*MSize/2 + i*MSize + j);
            *(tmp2 + i*MSize/2 + j) = *(aMtx2 + i*MSize + j);
            }
        int* p2 = MlplyMatrix(tmp1, tmp2, MSize/2);
        for(int i = 0; i < (MSize/2); ++i)
            for(int j = 0; j < (MSize/2); ++j)
            {
            *(tmp1 + i*MSize/2 + j) = *(aMtx1 + i*MSize + j);
            *(tmp2 + i*MSize/2 + j) = *(aMtx2 + MSize/2 + i*MSize + j) - *(aMtx2 + MSize*MSize/2 + MSize/2 + i*MSize + j);
            }
        int* p3 = MlplyMatrix(tmp1, tmp2, MSize/2);
        for(int i = 0; i < (MSize/2); ++i)
            for(int j = 0; j < (MSize/2); ++j)
            {
            *(tmp1 + i*MSize/2 + j) = *(aMtx1 + i*MSize + MSize*MSize/2 + MSize/2 + j);
            *(tmp2 + i*MSize/2 + j) = *(aMtx2 + MSize*MSize/2 + i*MSize + j) - *(aMtx2 + i*MSize + j);
            }
        int* p4 = MlplyMatrix(tmp1, tmp2, MSize/2);
        for(int i = 0; i < (MSize/2); ++i)
            for(int j = 0; j < (MSize/2); ++j)
            {
            *(tmp1 + i*MSize/2 + j) = *(aMtx1 + i*MSize + j) + *(aMtx1 + MSize*MSize/2 + MSize/2 + i*MSize + j);
            *(tmp2 + i*MSize/2 + j) = *(aMtx2 + MSize*MSize/2 + MSize/2 + i*MSize + j);
            }
        int* p5 = MlplyMatrix(tmp1, tmp2, MSize/2);
        for(int i = 0; i < (MSize/2); ++i)
            for(int j = 0; j < (MSize/2); ++j)
            {
            *(tmp1 + i*MSize/2 + j) = *(aMtx1 + MSize*MSize/2 + i*MSize + j) - *(aMtx1 + i*MSize + j);
            *(tmp2 + i*MSize/2 + j) = *(aMtx2 + i*MSize + j) + *(aMtx2 + i*MSize + MSize/2 + j);
            }
        int* p6 = MlplyMatrix(tmp1, tmp2, MSize/2);
        for(int i = 0; i < (MSize/2); ++i)
            for(int j = 0; j < (MSize/2); ++j)
            {
            *(tmp1 + i*MSize/2 + j) = *(aMtx1 + MSize*MSize/2 + i*MSize + j) - *(aMtx1 + MSize/2 + MSize*MSize/2 + i*MSize + j);
            *(tmp2 + i*MSize/2 + j) = *(aMtx2 + MSize*MSize/2 + i*MSize + j) + *(aMtx2 + i*MSize + MSize*MSize/2 + MSize/2 + j);
            }
        int* p7 = MlplyMatrix(tmp1, tmp2, MSize/2);

        for(int i = 0; i < (MSize/2); ++i)
            for(int j = 0; j < (MSize/2); ++j)
            {
            *(AnsMatrix + i*MSize/2 + j) = *(p1 + i + j) + *(p4 + i + j) - *(p5 + i + j) + *(p7 + i + j);
            *(AnsMatrix + MSize/2 + i*MSize/2 + j) = *(p3 + i + j) + *(p5 + i + j);
            *(AnsMatrix + MSize*MSize/2 + j) = *(p2 + i + j) + *(p4 + i + j);
            *(AnsMatrix + MSize*MSize/2 + MSize/2 + i*MSize/2 + j) = *(p1 + i + j) - *(p2 + i + j) + *(p3 + i + j) + *(p6 + i + j);
            }
        free(p1);
        free(p2);
        free(p3);
        free(p4);
        free(p5);
        free(p6);
        free(p7);
        }
    return AnsMatrix;
    }
