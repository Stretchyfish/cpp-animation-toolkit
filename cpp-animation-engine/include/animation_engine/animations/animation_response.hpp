

namespace anim
{
    namespace animation
    {
        enum AnimationState
        {
            NotStarted,
            OnGoing,
            Finished,
            Invalid
        };

        struct AnimationResponse
        {
            float position_x;
            float position_y;
            AnimationState state;
        };
    }
}