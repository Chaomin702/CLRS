#pragma once

template <typename Tv,typename Te>
void Graph<Tv, Te>::setUnreachable(int i){
	for (int k = 0; k < n; k++){
		if (exists(i, k))
			weight(i, k) = MAX_WEIGHT;
		if (exists(k, i))
			weight(k, i) = MAX_WEIGHT;
	}
}