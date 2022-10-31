
#include "karint/graphic/pipeline/RenderUnit.h"

namespace karint {
    class MaterialUnit : public RenderUnit {

    public:
        int binding;
        void update() override;
        void init(RenderPipeline *pipeline) override;
        uint64_t unitBits() override;
    };
}


