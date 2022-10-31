#pragma once

#include <vector>
#include "RenderUnit.h"

namespace karint {
    class RenderPipeline {
    private:
        std::vector<RenderUnit *> units;
        uint32_t unitsMask = 0;
        unsigned long unitsLocationBits = 0;
        int uniformBlockId;

    public:
        ShaderProgram shaderProgram;

        /**
         * Adds an unit to the unit list and includes it to the pipeline.
         * Each of units in the list id updated after calling the 'update' method.
         */
        void add(RenderUnit *unit);



        /**
         * Sets given shader program to the pipelina and init all render units
         * @param program The shader program
         */
        void setShaderProgram(ShaderProgram program);

        /**
         * Registers new uniform block id for the shader program
         *
         * @return uniform block id
         */
        int registerUniformBlockId();


        template<typename T>
        inline T *operator[](uint64_t index) {
            return units[0xFF & (unitsLocationBits >> (4 * renderUnitIntId(index)))];
        }

        /**
         * Updates all units in the pipeline expect units that support only the force update.
         * **/
        void update();
    };
}


