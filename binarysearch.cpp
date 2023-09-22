// auntduda's template
// vou melhorar isso aqui pra fazer fofo que nem o da nathalia
// lembretes: ver o tamanho do input e o tempo limite; simular o obvio na mao pra DEPOIS ter uma estrategia; sem ideia? abre o caderno e procura alguma coisa; inventar casos de teste FACTIVEIS, nao apenas aleatorios;


#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, count; cin >> n >> count;
    
    vector<int> a(n);
    
    for(int i=0; i<n; i++) cin >> a[i];
    
    while(count--)
    {
      int x; cin >> x;
      
      // nao eh possivel que esse cacete nao passa na busca binaria
      
    //   int l=0, r=n-1, ans=-1;
      
    //   while(l<r)
    //   {
    //       int mid=(l+(r-1))/2;
          
    //       if(x==a[mid])
    //       {
    //           ans=mid;
    //           break;
    //       }else if(x<a[mid])
    //       {
    //           r=mid-1;
    //           if(x==a[r])
    //           {
    //               ans=r;
    //           }
    //       }else
    //       {
    //           l=mid+1;
    //           if(x==a[l])
    //           {
    //               ans=l;
    //           }
    //       }
    //   }
      
    //   if(x==a[0]) ans=0;
      
    //   cout << ans << "\n";
    
    int ans=-1;
    
    int aux = lower_bound(a.begin(), a.end(), x) - a.begin();
    
    if(aux!=n) ans=aux;
    if(a[ans]!=x) ans=-1;
    
    cout << ans << endl;
    }
    
    return 0;
}
