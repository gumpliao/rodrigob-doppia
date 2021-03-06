/*
 *  Copyright 2008-2012 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <thrust/detail/config.h>
#include <thrust/system/cuda/detail/copy.h>
#include <thrust/system/cuda/detail/copy_device_to_device.h>
#include <thrust/system/cuda/detail/copy_cross_system.h>

namespace thrust
{
namespace system
{
namespace cuda
{
namespace detail
{


template<typename InputIterator,
         typename OutputIterator>
  OutputIterator copy(tag,
                      InputIterator first,
                      InputIterator last,
                      OutputIterator result)
{
  return thrust::system::cuda::detail::copy_device_to_device(first,last,result);
} // end copy()


template<typename InputIterator,
         typename OutputIterator>
  OutputIterator copy(cuda_to_cpp,
                      InputIterator first,
                      InputIterator last,
                      OutputIterator result)
{
  return thrust::system::cuda::detail::copy_cross_system(first,last,result);
} // end copy()


template<typename InputIterator,
         typename OutputIterator>
  OutputIterator copy(cpp_to_cuda,
                      InputIterator first,
                      InputIterator last,
                      OutputIterator result)
{
  return thrust::system::cuda::detail::copy_cross_system(first,last,result);
} // end copy()


template<typename InputIterator,
         typename Size,
         typename OutputIterator>
  OutputIterator copy_n(tag,
                        InputIterator first,
                        Size n,
                        OutputIterator result)
{
  return thrust::system::cuda::detail::copy_device_to_device(first,first+n,result);
} // end copy_n()


template<typename InputIterator,
         typename Size,
         typename OutputIterator>
  OutputIterator copy_n(cuda_to_cpp,
                        InputIterator first,
                        Size n,
                        OutputIterator result)
{
  return thrust::system::cuda::detail::copy_cross_system_n(first,n,result);
} // end copy_n()


template<typename InputIterator,
         typename Size,
         typename OutputIterator>
  OutputIterator copy_n(cpp_to_cuda,
                        InputIterator first,
                        Size n,
                        OutputIterator result)
{
  return thrust::system::cuda::detail::copy_cross_system_n(first,n,result);
} // end copy_n()


} // end detail
} // end cuda
} // end system
} // end thrust

