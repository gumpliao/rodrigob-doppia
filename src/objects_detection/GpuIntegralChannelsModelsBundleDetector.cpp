#include "GpuIntegralChannelsModelsBundleDetector.hpp"

#include "helpers/get_option_value.hpp"
#include "helpers/Log.hpp"

#include <boost/foreach.hpp>

#include <stdexcept>

namespace
{

std::ostream & log_info()
{
    return  logging::log(logging::InfoMessage, "GpuIntegralChannelsModelsBundleDetector");
}

std::ostream & log_debug()
{
    return  logging::log(logging::DebugMessage, "GpuIntegralChannelsModelsBundleDetector");
}

std::ostream & log_warning()
{
    return  logging::log(logging::WarningMessage, "GpuIntegralChannelsModelsBundleDetector");
}

std::ostream & log_error()
{
    return  logging::log(logging::ErrorMessage, "GpuIntegralChannelsModelsBundleDetector");
}

} // end of anonymous namespace

namespace doppia {

GpuIntegralChannelsModelsBundleDetector::GpuIntegralChannelsModelsBundleDetector(
        const boost::program_options::variables_map &options,
        boost::shared_ptr<IntegralChannelsDetectorModelsBundle> detector_model_p,
        boost::shared_ptr<AbstractNonMaximalSuppression> non_maximal_suppression_p,
        const float score_threshold, const int additional_border)
    : BaseIntegralChannelsDetector(options,
                                   boost::shared_ptr<SoftCascadeOverIntegralChannelsModel>(),
                                   non_maximal_suppression_p, score_threshold, additional_border),
      GpuIntegralChannelsDetector(
          options,
          boost::shared_ptr<SoftCascadeOverIntegralChannelsModel>(),
          non_maximal_suppression_p,
          score_threshold, additional_border),
      BaseIntegralChannelsModelsBundleDetector(options,
                                               detector_model_p)
{

    const bool ignore_cascade = get_option_value<bool>(options, "objects_detector.ignore_soft_cascade");
    use_the_detector_model_cascade = (ignore_cascade == false) and detector_model_p->has_soft_cascade();

    if(use_the_detector_model_cascade)
    {
        log_info() << "Will use the model soft cascade at run time" << std::endl;
    }
    else
    {
        log_info() << "Will not use a soft cascade at run time" << std::endl;
    }

    return;
}


GpuIntegralChannelsModelsBundleDetector::~GpuIntegralChannelsModelsBundleDetector()
{
    // nothing to do here
    return;
}


} // end of namespace doppia

