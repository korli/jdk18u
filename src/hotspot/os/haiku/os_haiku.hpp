/*
 * Copyright (c) 1999, 2010, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef OS_HAIKU_OS_HAIKU_HPP
#define OS_HAIKU_OS_HAIKU_HPP

// Haiku_OS defines the interface to the Haiku operating system

// Information about the protection of the page at address '0' on this os.
static bool zero_page_read_protected() { return true; }

class Haiku {
  friend class os;

 protected:

  static julong _physical_memory;
  static pthread_t _main_thread;
  static int _page_size;

  static julong available_memory();
  static julong physical_memory() { return _physical_memory; }
  static void initialize_system_info();

 public:
  static void init_thread_fpu_state();
  static pthread_t main_thread(void)                                { return _main_thread; }
  
  static pid_t gettid();

  static int page_size(void)                                        { return _page_size; }
  static void set_page_size(int val)                                { _page_size = val; }

  static intptr_t* ucontext_get_sp(const ucontext_t* uc);
  static intptr_t* ucontext_get_fp(const ucontext_t* uc);

  static jlong fast_thread_cpu_time(Thread* thread, bool user_sys_cpu_time);

private:
  static void print_uptime_info(outputStream* st);
};

#endif // OS_HAIKU_OS_HAIKU_HPP
