#include "intersection.h"

intersection::intersection(){}
intersection::~intersection(){}

void intersection::set_GA_params(GA_param_list& lst)
{
	lst.generation_size = 20;
	lst.max_generation = 150;
	lst.crossover_prob = 0.5;
	lst.max_iterations = 30;
	lst.mutation_prob = 0.1;
	lst.seed = std::chrono::system_clock::now().time_since_epoch().count();
	lst.tolerance = 1.0e-3;
}


double intersection::run_truck_tandem_drone(string drone_type)
{
	cout << "Running truck & tandem drone method with drone type " << drone_type << "\n";
	int additional_adr = 2;
	double max_flight_distance = 1000; // in metres
	rural_drone arcadian_drone;
	read_data rd("postal_data.txt");
	rd.fill_data();
	clustering cl(rd);
	cl.run_clustering();
	cl.add_depot();
	GA_param_list set_params;
	set_GA_params(set_params);
	genetic_algorithm<Circuit, address_metadata> tsp_ga(set_params, cl.centroids);
	result Result = tsp_ga.run_algorithm_genetic(&fitness, &initialise_circuit_v, &check_truck_route_validity);
	arcadian_drone.drone_multi_delivery(cl.k, additional_adr, cl.cluster_regions,  Result.circuit_vector, )


	//truck t1(no_of_drones_req);
	




	return 0.0;
}

void intersection::do_tests()
{
	run_tests();
}

void intersection::run_charging_port_tandem_drone(string drone_type)
{
	cout << "Running drone & charging stations method with drone type " << drone_type << "\n";

}
