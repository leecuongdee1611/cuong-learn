#!/bin/bash
echo "*** Program Result:"
cd ./build/00-multithread/A-thread-create
./thread_create
echo ""

echo "*** Program Result:"
cd ../../../
cd ./build/00-multithread/B-join-detach
./join_detach
echo ""
