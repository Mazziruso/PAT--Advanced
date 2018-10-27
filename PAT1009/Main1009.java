package PAT1009;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class Main1009 {
    public static void main(String[] args) throws IOException {
        Complex[] x;
        Complex[] y;
        Complex[] z;
        int n;
        int len;
        int temp;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
        String[] strs;

        while((str=br.readLine())!=null) {

            strs = str.split(" ");
            n = Integer.valueOf(strs[0]);
            if(n==0) {
                System.out.println(0);
                continue;
            }
            len = Integer.valueOf(strs[1])+1;
            x = new Complex[len];
            for(int i=0; i<len; i++) {
                x[i] = new Complex();
            }
            for(int i=1; i<=n; i++) {
                temp = Integer.valueOf(strs[i*2-1]);
                x[temp] = new Complex(Double.valueOf(strs[i*2]));
            }

            strs = br.readLine().split(" ");
            n = Integer.valueOf(strs[0]);
            if(n==0) {
                System.out.println(0);
                continue;
            }
            len = Integer.valueOf(strs[1])+1;
            y = new Complex[len];
            for(int i=0; i<len; i++) {
                y[i] = new Complex();
            }
            for(int i=1; i<=n; i++) {
                temp = Integer.valueOf(strs[i*2-1]);
                y[temp] = new Complex(Double.valueOf(strs[i*2]));
            }

            z = FFT.convolve(x, y);

            n = 0;
            temp = 0;
            for (int i = 0; i < z.length; i++) {
                z[i].roundReal();
                if(z[i].real != 0) {
                    temp++;
                    n = i;
                }
            }

            if(temp!=0) {
                System.out.print(temp);
            } else {
                System.out.println(0);
            }

            for (int i = n; i >= 0; i--) {
                if(z[i].real != 0) {
                    System.out.print(" " + i + " " + z[i].real);
                }
            }
            System.out.println();

        }

    }
}

class Complex {
    public double real;
    public double imag;

    public Complex(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }

    public Complex(double real) {
        this(real,0);
    }

    public Complex() {
        this(0,0);
    }

    public Complex plus(Complex b) {
        return new Complex(this.real+b.real, this.imag+b.imag);
    }

    public Complex minus(Complex b) {
        return new Complex(this.real-b.real, this.imag-b.imag);
    }

    public Complex times(Complex b) {
        double real = this.real*b.real-this.imag*b.imag;
        double imag = this.real*b.imag+this.imag*b.real;
        return new Complex(real, imag);
    }

    public Complex conjugate() {
        return new Complex(this.real, -1.0*this.imag);
    }

    public Complex scale(double b) {
        return new Complex(this.real*b, this.imag*b);
    }

    public void roundReal() {
        this.real = Math.round(this.real*10)/10.0;
    }
}

class FFT {

    // compute the FFT of x[], assuming its length is a power of 2
    public static Complex[] fft(Complex[] x) {
        int n = x.length;

        // base case
        if (n == 1) return new Complex[]{x[0]};

        // radix 2 Cooley-Tukey FFT
        if (n % 2 != 0) {
            throw new IllegalArgumentException("n is not a power of 2");
        }

        // fft of even terms
        Complex[] even = new Complex[n / 2];
        for (int k = 0; k < n / 2; k++) {
            even[k] = x[2 * k];
        }
        Complex[] q = fft(even);

        // fft of odd terms
        Complex[] odd = even;  // reuse the array
        for (int k = 0; k < n / 2; k++) {
            odd[k] = x[2 * k + 1];
        }
        Complex[] r = fft(odd);

        // combine
        Complex[] y = new Complex[n];
        for (int k = 0; k < n / 2; k++) {
            double kth = -2 * k * Math.PI / n;
            Complex wk = new Complex(Math.cos(kth), Math.sin(kth));
            y[k] = q[k].plus(wk.times(r[k]));
            y[k + n / 2] = q[k].minus(wk.times(r[k]));
        }
        return y;
    }


    // compute the inverse FFT of x[], assuming its length is a power of 2
    public static Complex[] ifft(Complex[] x) {
        int n = x.length;
        Complex[] y = new Complex[n];

        // take conjugate
        for (int i = 0; i < n; i++) {
            y[i] = x[i].conjugate();
        }

        // compute forward FFT
        y = fft(y);

        // take conjugate again
        for (int i = 0; i < n; i++) {
            y[i] = y[i].conjugate();
        }

        // divide by n
        for (int i = 0; i < n; i++) {
            y[i] = y[i].scale(1.0 / n);
        }

        return y;

    }

    // compute the circular convolution of x and y
    public static Complex[] cconvolve(Complex[] x, Complex[] y) {

        // should probably pad x and y with 0s so that they have same length
        // and are powers of 2
        if (x.length != y.length) {
            throw new IllegalArgumentException("Dimensions don't agree");
        }

        int n = x.length;

        // compute FFT of each sequence
        Complex[] a = fft(x);
        Complex[] b = fft(y);

        // point-wise multiply
        Complex[] c = new Complex[n];
        for (int i = 0; i < n; i++) {
            c[i] = a[i].times(b[i]);
        }

        // compute inverse FFT
        return ifft(c);
    }


    // compute the linear convolution of x and y
    public static Complex[] convolve(Complex[] x, Complex[] y) {
        Complex ZERO = new Complex(0, 0);

        int fftLen = fftLength(x.length+y.length-1);

        Complex[] a = new Complex[fftLen];
        for (int i = 0; i < x.length; i++) a[i] = x[i];
        for (int i = x.length; i < fftLen; i++) a[i] = ZERO;

        Complex[] b = new Complex[fftLen];
        for (int i = 0; i < y.length; i++) b[i] = y[i];
        for (int i = y.length; i < fftLen; i++) b[i] = ZERO;

        return cconvolve(a, b);
    }

    private static int fftLength(int length) {
        int len;
        if(length<=4) {
            len = 4;
        } else if(length<=8) {
            len = 8;
        } else if(length<=16) {
            len = 16;
        } else if(length<=32) {
            len = 32;
        } else if(length<=64) {
            len = 64;
        } else if(length<=128) {
            len = 128;
        } else if(length<=256) {
            len = 256;
        } else if(length<=512) {
            len = 512;
        } else if(length<=1024) {
            len = 1024;
        } else {
            len = 2048;
        }

        return len;
    }

}
