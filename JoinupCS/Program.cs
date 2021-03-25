using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics; // Debug

namespace JoinupCS
{
    class Program
    {
        static void Main(string[] args)
        {
            bool ret;
            StringBuilder option = new StringBuilder(260);
            DllInterface dllif;

            Debug.Print("Start program");

            Console.WriteLine("Start");

            dllif = new DllInterface();

            dllif.Run();

            ret = DllInterface.JoinupStart("JoinUp", "Start");
            Console.WriteLine("joinup_stark OK=" + ret);

            ret = DllInterface.JoinupSetOpt(DllInterface.JoinupOpt.Start, "First");
            Console.WriteLine("joinup_setopt(1) OK=" + ret); ;

            ret = DllInterface.JoinupSetOpt(DllInterface.JoinupOpt.Transfer, "Second");
            Console.WriteLine("joinup_setopt(2) OK=" + ret);

            ret = DllInterface.JoinupGetOpt(DllInterface.JoinupOpt.Start, option);
            Console.WriteLine("joinup_setopt(1) OK=" + ret + ", option=" + option);

            ret = DllInterface.JoinupGetOpt(DllInterface.JoinupOpt.Transfer, option);
            Console.WriteLine("joinup_setopt(2) OK=" + ret + ", option=" + option);

            ret = DllInterface.JoinupStop("JoinUp", "Start");
            Console.WriteLine("joinup_stop OK="+ ret);

            Debug.Print("End program");
        }
    }
}
