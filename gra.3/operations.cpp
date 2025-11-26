
#include "output.h"
#include "operations.h"
#include <syncstream>
#include <thread>
#include <utility>
#include <latch>
using namespace std; 
latch latch_c(A_N);
latch latch_d(A_N);
latch latch_e(B_N);
latch latch_f(B_N);
latch latch_g(C_N);
latch latch_h(D_N + E_N);
latch latch_i(F_N);
latch latch_j(G_N + H_N + I_N);

pair<int, int> range_for_thread(int n, int thread_id)
{
    int start = (n * thread_id )/ NT;
    int end =( n * (thread_id + 1)) / NT;
    return { start, end };
}

void worker(int thread_id)
{

    {
        auto [s, e] = range_for_thread(A_N, thread_id);
        for (int i = s; i < e; ++i)
        {
            action('a', i + 1);
            latch_c.count_down();
            latch_d.count_down();
        }
    }

    {
        auto [s, e] = range_for_thread(B_N, thread_id);
        for (int i = s; i < e; ++i)
        {
            action('b', i + 1);
            latch_e.count_down();
            latch_f.count_down();
        }
    }

    {
        latch_c.wait();
        auto [s, e] = range_for_thread(C_N, thread_id);
        for (int i = s; i < e; ++i)
        {
            action('c', i + 1);
            latch_g.count_down();
        }
    }

    {
        latch_d.wait();
        auto [s, e] = range_for_thread(D_N, thread_id);
        for (int i = s; i < e; ++i)
        {
            action('d', i + 1);
            latch_h.count_down();
        }
    }
 
    {
        latch_e.wait();
        auto [s, e] = range_for_thread(E_N, thread_id);
        for (int i = s; i < e; ++i)
        {
            action('e', i + 1);
            latch_h.count_down();
        }
    }
  
    {
        latch_f.wait();
        auto [s, e] = range_for_thread(F_N, thread_id);
        for (int i = s; i < e; ++i)
        {
            action('f', i + 1);
            latch_i.count_down();
        }
    }
  
    {
        latch_g.wait();
        auto [s, e] = range_for_thread(G_N, thread_id);
        for (int i = s; i < e; ++i)
        {
            action('g', i + 1);
            latch_j.count_down();
        }
    }
   
    {
        latch_h.wait();
        auto [s, e] = range_for_thread(H_N, thread_id);
        for (int i = s; i < e; ++i)
        {
            action('h', i + 1);
            latch_j.count_down();
        }
    }
  
    {
        latch_i.wait();
        auto [s, e] = range_for_thread(I_N, thread_id);
        for (int i = s; i < e; ++i)
        {
            action('i', i + 1);
            latch_j.count_down();
        }
    }
   
    {
        latch_j.wait();
        auto [s, e] = range_for_thread(J_N, thread_id);
        for (int i = s; i < e; ++i)
        {
            action('j', i + 1);
        }
    }
}