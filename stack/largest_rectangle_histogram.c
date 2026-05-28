int largestRectangleArea(int* heights, int heightsSize) {
    int st[heightsSize + 1];
    int top = -1;
    int maxArea = 0;
    for (int i = 0; i <= heightsSize; i++) {
        int curr = (i == heightsSize) ? 0 : heights[i];
        while (top != -1 && curr < heights[st[top]]) {
            int h = heights[st[top--]];
            int width;
            if (top == -1)
                width = i;
            else
                width = i - st[top] - 1;

            int area = h * width;

            if (area > maxArea)
                maxArea = area;
        }

        st[++top] = i;
    }
    return maxArea;
}
