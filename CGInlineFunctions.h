//
//  CGInlineFunctions.h
//
//  Copyright (c) 2014 Ian Arawjo
//
//    Permission is hereby granted, free of charge, to any person obtaining a copy
//    of this software and associated documentation files (the "Software"), to deal
//    in the Software without restriction, including without limitation the rights
//    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//    copies of the Software, and to permit persons to whom the Software is
//    furnished to do so, subject to the following conditions:
//
//    The above copyright notice and this permission notice shall be included in all
//    copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//    SOFTWARE.
//

#ifndef CGInlineFunctions_h
#define CGInlineFunctions_h

CG_INLINE float
CGPointLength(CGPoint p) {
    return sqrt(p.x*p.x + p.y*p.y);
}

CG_INLINE void
CGPointPrint(CGPoint p) {
    NSLog(@"{%f, %f}", p.x, p.y);
}

CG_INLINE void
CGRectPrint(CGRect r) {
    NSLog(@"{%f, %f, %f, %f}", r.origin.x, r.origin.y, r.size.width, r.size.height);
}

CG_INLINE BOOL
CGPointIsZero(CGPoint p) {
    return p.x == 0 && p.y == 0;
}

CG_INLINE CGPoint
CGPointAbsolute(CGPoint p) {
    CGPoint q;
    q.x = fabsf(p.x);
    q.y = fabsf(p.y);
    return q;
}

CG_INLINE CGPoint
CGPointFlip(CGPoint p) {
    CGPoint q;
    q.x = -p.x;
    q.y = -p.y;
    return q;
}

CG_INLINE CGPoint
CGPointAdd(CGPoint p, CGPoint q) {
    CGPoint a;
    a.x = p.x + q.x;
    a.y = p.y + q.y;
    return a;
}

CG_INLINE float
CGPointDotProduct(CGPoint p, CGPoint q) {
    return p.x * q.x + p.y * q.y;
}

CG_INLINE CGPoint
CGPointMultiply(CGPoint p, float scalar) {
    CGPoint m;
    m.x = p.x * scalar;
    m.y = p.y * scalar;
    return m;
}

CG_INLINE CGPoint
CGPointVectorMultiply(CGPoint p, CGPoint q) { // *Not cross-product. Multiplies x and y components.
    CGPoint m;
    m.x = p.x * q.x;
    m.y = p.y * q.y;
    return m;
}

CG_INLINE CGPoint
CGPointFrom(CGPoint start, CGPoint end) {
    CGPoint p;
    p.x = end.x - start.x;
    p.y = end.y - start.y;
    return p;
}

CG_INLINE CGPoint
CGPointNormalize(CGPoint p) {
    CGPoint n;
    n.x = p.x; n.y = p.y;
    float len = sqrt(p.x*p.x + p.y*p.y);
    if(len < 0.00000001) return p;
    n.x /= len;
    n.y /= len;
    return n;
}

CG_INLINE float
CGPointNormDotProduct(CGPoint p, CGPoint q) {
    p = CGPointNormalize(p);
    q = CGPointNormalize(q);
    return p.x * q.x + p.y * q.y;
}

CG_INLINE CGPoint
CGPointRandomInRect(CGRect r) {
    CGPoint n;
    n.x = r.origin.x + (rand() % 2048) / 2048. * r.size.width;
    n.y = r.origin.y + (rand() % 2048) / 2048. * r.size.height;
    return n;
}

CG_INLINE CGPoint
CGPointClampInRect(CGPoint p, CGRect r) {
    if(p.x < r.origin.x) p.x = r.origin.x;
    else if(p.x > CGRectGetMaxX(r)) p.x = CGRectGetMaxX(r);
    if(p.y < r.origin.y) p.y = r.origin.y;
    else if(p.y > CGRectGetMaxY(r)) p.y = CGRectGetMaxY(r);
    return p;
}

#endif
