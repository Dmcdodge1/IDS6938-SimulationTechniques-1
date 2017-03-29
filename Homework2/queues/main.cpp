/*
  A simple program that simulates 5 MM1 queues at an airport. The first queue
  feeds 3 other queues that work in parallel. These feed a final queue.
  Simulation runs until error below threshold and, at the end,
  a performance evaluation report is shown, and logs are generated
  for plotting and analysis.
*/

using namespace std;

#include <random>
#include "customer.h"
#include "mm1_queue.h"


std::random_device rd;

void pause()
{
 std::string sInputString;
 // Wait for input from stdin (the keyboard)
 cout << "Continue (y)?";
 std::cin >> sInputString;
}



int main(int argc, char* argv[])
{
   int next = 0;
//   test_random_number_generator();

   for (int cur_lambda = 3; cur_lambda < 34; cur_lambda++) {
      
	   //TODO Create MM1_Queue objects to capture the airport senario.
	   MM1_Queue BaggageCheck;
	   BaggageCheck.set_file_names("BaggageCheck_log.txt", "BaggageCheck_wait.txt", "BaggageCheck_service.txt");
	   BaggageCheck.set_lambda(6);
	   BaggageCheck.set_mu(53);
	   BaggageCheck.initialize();
	   BaggageCheck.set_seed(rd(), rd());

	   MM1_Queue Securitycheck1;
	   Securitycheck1.set_file_names("Securitycheck1_log.txt", "Securitycheck1_wait.txt", "Securitycheck1_service.txt");
	   Securitycheck1.set_lambda(6);
	   Securitycheck1.set_mu(20);
	   Securitycheck1.autogenerate_new_arrivals(false);
	   Securitycheck1.initialize();
	   Securitycheck1.set_seed(rd(), rd());

	   MM1_Queue Securitycheck2;
	   Securitycheck2.set_file_names("Securitycheck2_log.txt", "Securitycheck2_wait.txt", "Securitycheck2_service.txt");
	   Securitycheck2.set_lambda(6);
	   Securitycheck2.set_mu(20);
	   Securitycheck2.autogenerate_new_arrivals(false);
	   Securitycheck2.initialize();
	   Securitycheck2.set_seed(rd(), rd());

	   MM1_Queue Securitycheck3;
	   Securitycheck3.set_file_names("Securitycheck3_log.txt", "Securitycheck3_wait.txt", "Securitycheck3_service.txt");
	   Securitycheck3.set_lambda(6);
	   Securitycheck3.set_mu(20);
	   Securitycheck3.autogenerate_new_arrivals(false);
	   Securitycheck3.initialize();
	   Securitycheck3.set_seed(rd(), rd());

	   MM1_Queue Boardingcall;
	   Boardingcall.set_file_names("Boardingcall_log.txt", "Boardingcall_wait.txt", "Boardingcall_service.txt");
	   Boardingcall.set_lambda(6);
	   Boardingcall.set_mu(80);
	   Boardingcall.initialize();
	   Boardingcall.set_seed(rd(), rd());
	   //************************************************************


   for (; 
		//TODO: add is_within_error_range check
	   !BaggageCheck.is_within_error_range(0.002) ||
	   !Securitycheck1.is_within_error_range(0.002) ||
	   !Securitycheck2.is_within_error_range(0.002) ||
	   !Securitycheck3.is_within_error_range(0.002) ||
	   !Boardingcall.is_within_error_range(0.002)
       ;)
   {
	   Customer cust = BaggageCheck.process_next_event();    // =  TODO: process next event;
	   Customer cust2 = Securitycheck1.process_next_event();   // =  TODO: process next event;
	   Customer cust3 = Securitycheck2.process_next_event();   // =  TODO: process next event;
	   Customer cust4 = Securitycheck3.process_next_event();   // =  TODO: process next event;
	   Customer cust5 = Boardingcall.process_next_event(); //TODO: one more process_next_event for the last object.

       if (cust.get_type() == Customer::COMPLETED()){
          switch(next){
            case 0:
				//TODO add_external_arrival() for your security gates;
				Securitycheck1.add_external_arrival();
                 break;
            case 1:
				//TODO add_external_arrival() for your security gates;
				Securitycheck2.add_external_arrival();
                 break;
            case 2:
                //TODO add_external_arrival() for your security gates;
				Securitycheck3.add_external_arrival();
                 break;
          }
          next++;
          if (next%3==0) next = 0;
       }
       if (cust2.get_type() == Customer::COMPLETED() || cust3.get_type() == Customer::COMPLETED() || cust4.get_type() == Customer::COMPLETED()){
		   //TODO add_external_arrival(); on your final boarding MM1_Queue object
		   Boardingcall.add_external_arrival();
       }
   }



   //TODO Output statistics airport senario.
   BaggageCheck.output(); cout << "-------------------------------" << endl;
   Securitycheck1.output(); cout << "-------------------------------" << endl;
   Securitycheck2.output(); cout << "-------------------------------" << endl;
   Securitycheck3.output(); cout << "-------------------------------" << endl;
   Boardingcall.output(); cout << "-------------------------------" << endl;
   //**************************************************************************



   }

   return(0);
}

