int print2largest(int arr[], int n) {
	    // code here
        int max=0;
	    for(int i=0;i<n;i++){
	        if(max<arr[i]){
	            max = arr[i];
	        }
	    }
        int secmax=-1;
        for(int i=0;i<n;i++){
	        if(secmax<arr[i] && arr[i]!=max ){
	            secmax = arr[i];
	        }
	    }
	    return secmax;

	}