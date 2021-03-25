using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics; // Debug
using System.Runtime.InteropServices;

namespace JoinupCS
{
    public class DllInterface
    {
#if false
        extern "C" JOINUP_API BOOLEAN joinup_start(PTSTR Path, PTSTR Name);

        extern "C" JOINUP_API BOOLEAN joinup_stop(PTSTR Path, PTSTR Name);

        extern "C" JOINUP_API BOOLEAN joinup_setopt(JOINUP_OPT Option, PTSTR Name);
#endif

        public enum JoinupOpt : uint
        {
            Stop = 0,
            Start = 1,
            Transfer = 2
        }

        [DllImport("Joinup.dll", SetLastError = true, EntryPoint = "joinup_start")]
        public static extern bool JoinupStart(string Path, string Name);

        [DllImport("Joinup.dll", SetLastError = true, EntryPoint = "joinup_stop")]
        public static extern bool JoinupStop(string Path, string Name);

        [DllImport("Joinup.dll", SetLastError = true, EntryPoint = "joinup_setopt")]
        public static extern bool JoinupSetOpt(JoinupOpt Option, string Name);

        [DllImport("Joinup.dll", SetLastError = true, EntryPoint = "joinup_getopt")]
        public static extern bool JoinupGetOpt(JoinupOpt Option, StringBuilder Name);

        public void Run()
        {
            Debug.Print("Start DllInterface");

            Console.WriteLine("DllInterface");
        }
    }
}
