//cuadratico
int c;
vector<int> v,sub;
int subseq(int posAct){
    if(posAct == 0) return 1;
    if(sub[posAct] != -1) return sub[posAct];
    sub[posAct] = 1;
    for(int i = 1; i<c; i++){
        if(v[posAct-i] < v[posAct]){
            if( posAct - i >= 0){
                sub[posAct] = max(sub[posAct] , subseq(posAct-i) +  1);
            }else{
                break;
            }
        }
    }
    return sub[posAct];
}
signed main (){
    std::ios::sync_with_stdio(false);cin.tie(0);
    cin>>c;
    v.resize(c);
    for(int i = 0; i<c; i++){
        cin>>v[i];
    }
    sub.assign(c,-1);
    int res = 1;
    for(int i = 1; i<c; i++){
        res = max(res, subseq(c-i));
    } 
    cout<<res;
  return 0;
}


//opcion greedy nlogn 

void printLis(int end,vector<int>&p, vector<int>&v){
	if(p[end] == -1) {cout<<v[end]<<endl;return;}
	printLis(p[end],p,v);
	cout<<v[end]<<endl;
}

signed main (){
	std::ios::sync_with_stdio(false);cin.tie(0);
	vector<int> v;
	int x;
	while(cin>>x){
		v.push_back(x);
	}
	int n = (int)v.size();
	int k=0,lie;
	vector<int>l(n,0),li(n,0),p(n,-1);
	for(int i = 0; i<n;i++){
		int pos = lower_bound(l.begin(),l.begin()+k,v[i]) - l.begin();
		l[pos] = v[i];
		li[pos] = i;
		p[i] = -1;
		if(pos){
			p[i] = li[pos-1];
		}
		if(pos == k){
			k=pos+1;
			lie = i;
		}
	}
	cout<<k<<endl;
	cout<<"-"<<endl;
	printLis(lie,p,v);

    return 0;
}
