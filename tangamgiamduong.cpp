//6.sap xep tang dan so am so duong giam dan
void HoanVi(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void SapXepSoDuongTangDanVaSoAmGiamDan(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > 0 && a[j] > 0 && a[i] > a[j])
            {
                HoanVi(a[i], a[j]);
            }
            else if(a[i] < 0 && a[j] < 0 && a[i] < a[j])
            {
                HoanVi(a[i], a[j]);
            }
        }
    }
} 
