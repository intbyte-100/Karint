#include "karint/graphic/pipeline/RenderUnit.h"

namespace karint {
    class ColorUnit : public RenderUnit {
    private:
        Uniform uniform;

    public:
        glm::vec3 color;
        void update() override;
        void init(RenderPipeline *pipeline) override;
        uint64_t unitBits() override;
    };
}


