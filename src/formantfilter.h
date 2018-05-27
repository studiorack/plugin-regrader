/**
 * The MIT License (MIT)
 *
 * based on public source code by alex@smartelectronix.com, adapted
 * by Igor Zinken - http://www.igorski.nl
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
#ifndef __FORMANTFILTER_H_INCLUDED__
#define __FORMANTFILTER_H_INCLUDED__

#include "lfo.h"

namespace Igorski {
class FormantFilter {

    public:
        FormantFilter( double aVowel );
        ~FormantFilter();

        double getVowel();
        void setVowel( double aVowel );

        void process( float* inBuffer, int bufferSize );

        void setLFO( float LFORatePercentage, float LFODepth );
        void cacheLFO();
        LFO* lfo;

        // vowel value ranges at which the phoneme sound changes

        static const int VOWEL_A = 0;
        static const int VOWEL_E = 1;
        static const int VOWEL_I = 2;
        static const int VOWEL_O = 3;
        static const int VOWEL_U = 4;

        // a vowel of "0" basically bypasses this filter, lets
        // create a tiny value to engage the filter at VOWEL_A
        static const float MIN_VOWEL() { return 0.000001f; };

        bool hasLFO;

    private:
        double  _vowel;
        double _currentCoeffs[ 11 ];
        double _coeffs[ 5 ][ 11 ];
        double _memory[ 10 ];

        void cacheCoeffs();
        void calcCoeffs();

        float _lfoDepth;
        float _lfoRange;
        float _lfoMin;
        float _lfoMax;
        double _tempVowel;
};
}

#endif