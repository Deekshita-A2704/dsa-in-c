bool isPossible(int* target, int targetSize) {
    long long sum = 0;

    while(1) {
        int mx = 0, idx = 0;

        for(int i = 0; i < targetSize; i++) {
            sum += target[i];
            if(target[i] > mx)
                mx = target[idx = i];

        }

        if (mx == 1) return true;

        long long rest = sum - mx;

        if(rest == 0 || rest >= mx)
            return false;
        target[idx] = mx % rest;

        if(target[idx] == 0)
            target[idx] = rest;

        sum = 0;
    }
}
