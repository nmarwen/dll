//=======================================================================
// Copyright (c) 2014-2015 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include "dll/conv_rbm.hpp"
#include "dll/dbn.hpp"

template<typename DBN>
void test_dbn(){
    DBN dbn;

    dbn.display();

    std::vector<etl::fast_dyn_matrix<double, 1, 28, 28>> images;
    std::vector<uint8_t> labels;

    dbn.pretrain(images, 10);
    dbn.predict(images[1]);

    auto probs = dbn.activation_probabilities(images[1]);
}

int main(){
    //Basic example

    typedef dll::dbn_desc<
        dll::dbn_layers<
        dll::conv_rbm_desc_square<1, 28, 40, 12, dll::momentum, dll::batch_size<50>>::rbm_t,
        dll::conv_rbm_desc_square<40, 12, 40, 6, dll::momentum, dll::batch_size<50>>::rbm_t>>::dbn_t dbn_1;

    //Test them all

    test_dbn<dbn_1>();

    return 0;
}