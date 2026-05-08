#include "operations_research_i.h"

int64_t newtonRaphsonSqrt(int64_t n) {

}

int64_t num_points_of_interest(int x0, int y0, int r) {
    int64_t up = y0 + r, down = y0 - r;
    int64_t left, right;
    int64_t verticalDistance;
    int64_t horizontalHalfLength;

    for (int i = up; i > y0; i--) {
        verticalDistance = i - y0;
        horizontalHalfLength = newtonRaphsonSqrt(r * r - verticalDistance * verticalDistance);

    }
}

// f(x) = x^(1/2)
// f'(x) = 