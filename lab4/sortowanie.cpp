/*
 * stackonarray.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: serek8
 */

class Source1
{
    public Scanner scan = new Scanner(System.in);

    public static void main(String[] args)
    {
        int l = scan.nextInt();
        while (l > 0)
        {
            int n = scan.nextInt();
            Source1 tab = new Source1(n);

            for (int i = 0; i < n; i++)
            {
                tab.t[i] = scan.nextLong();
            }
            tab.quickSort();

            for (int i = 0; i < n; i++)
            {
                System.out.print(tab.t[i] + " ");
            }
            System.out.println("");

            l--;
        }
    }

    private long[] t;
    private int size;
    java.util.Random random;

    public Source1(int size)
    {
        this.t = new long[size];
        this.size = size;
        random = new Random();
    }

    private:

    int partition(int l, int r)
    {
        int pivot = random.nextInt(r - l) + l;
        long v = t[pivot];
        int i = l - 1;
        int j = r + 1;
        do
        {
            do
            {
                i++;
            } while (i < r && t[i] < v);

            do
            {
                j--;
            } while (j >= l && t[j] > v);

            if (i < j)
            {
                long tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        } while (i < j);
        return j;
    }

    public:
    void quickSort()
    {
        Stos stos = new Stos(50);
        stos.push(new Pair(0, size - 1));

        do
        {
            Pair p = stos.pop();
            int l = p.l;
            int r = p.r;
            while (l < r)
            {
                int j = partition(l, r);
                if (j - l > r - j)
                {
                    stos.push(new Pair(l, j - 1));
                    l = j + 1;
                } else {
                    stos.push(new Pair(j + 1, r));
                    r = j - 1;
                }
            }
        } while (!stos.pusty());
    }

    private class Pair
    {
        int l, r;

        public Pair(int l, int r)
        {
            this.l = l;
            this.r = r;
        }
    }
