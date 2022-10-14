#pragma once

#include <vector>
#include "RenderUnit.h"

namespace karint {
    class RenderPipeline {
    private:
        std::vector<RenderUnit*> units;
        uint32_t unitsMask = 0;
        unsigned long unitsLocationBits = 0;
    public:
        ShaderProgram shaderProgram;

        /**
         * Adds an unit to the unit list and includes it to the pipeline.
         * Each of units in the list id updated after calling the 'update' method.
         * **/
        void add(RenderUnit *unit);

        /**
         * Updates all units in the pipeline expect units that support only the force update.
         * **/
        void update();
    };
}


