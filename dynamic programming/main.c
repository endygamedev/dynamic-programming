int arr_len(int * x) {
    return sizeof(x)/sizeof(x[0]);
}

int main()
{
    int* y = {1, 1, 1, 1, 1};
    printf("%d\n", arr_len(y));
    return 0;
}

