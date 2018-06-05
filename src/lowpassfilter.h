/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Igor Zinken - http://www.igorski.nl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __LOWPASSFILTER_H_INCLUDED__
#define __LOWPASSFILTER_H_INCLUDED__

/**
 * a simple two pole low-pass filter
 */
namespace Igorski {
class LowPassFilter
{
    public:
        LowPassFilter( float cutoff );
        ~LowPassFilter();

        float getCutoff();
        void setCutoff( float value);

        void store();
        void reset();

        float processSingle( float sample );

    protected:
        float x1, x2, y1, y2;
        float orgx1, orgx2, orgy1, orgy2;
        float a0, a1, a2, b0, b1, b2, w0, alpha;

        float _cutoff;
};
}

#endif
