### Results

We found 48 strongly connected components, but with one strongly connected components that has the majority of airport nodes (namely 29th strongly connected component with 3127 nodes). Note not all the airports are strongly connected. We were expecting one single strongly connected component, but we realized that this was due to route.dat not having all the actual routes. There are airport nodes that can be reached from other airports, but that do not have flights leaving that airport, which makes no sense. Also, some routes might not be present because we erased some vertices without openflight code (n/a) and edges incoming or outcoming to those vertices.

