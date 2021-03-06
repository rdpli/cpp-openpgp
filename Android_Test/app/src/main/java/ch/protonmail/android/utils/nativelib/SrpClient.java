// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

package ch.protonmail.android.utils.nativelib;

import java.util.concurrent.atomic.AtomicBoolean;
import javax.annotation.CheckForNull;
import javax.annotation.Nonnull;

public abstract class SrpClient {
    /**ExpandHash */
    @Nonnull
    public static byte[] expandHash(@Nonnull byte[] input)
    {
        return CppProxy.expandHash(input);
    }

    /**SRP */
    @Nonnull
    public static SrpProofs generateProofs(int bitLength, @Nonnull byte[] modulusRepr, @Nonnull byte[] serverEphemeralRepr, @Nonnull byte[] hashedPasswordRepr)
    {
        return CppProxy.generateProofs(bitLength,
                                       modulusRepr,
                                       serverEphemeralRepr,
                                       hashedPasswordRepr);
    }

    @Nonnull
    public static byte[] generateVerifier(int bitLength, @Nonnull byte[] modulusRepr, @Nonnull byte[] hashedPasswordRepr)
    {
        return CppProxy.generateVerifier(bitLength,
                                         modulusRepr,
                                         hashedPasswordRepr);
    }

    private static final class CppProxy extends SrpClient
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void _djinni_private_destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            _djinni_private_destroy();
            super.finalize();
        }

        @Nonnull
        public static native byte[] expandHash(@Nonnull byte[] input);

        @Nonnull
        public static native SrpProofs generateProofs(int bitLength, @Nonnull byte[] modulusRepr, @Nonnull byte[] serverEphemeralRepr, @Nonnull byte[] hashedPasswordRepr);

        @Nonnull
        public static native byte[] generateVerifier(int bitLength, @Nonnull byte[] modulusRepr, @Nonnull byte[] hashedPasswordRepr);
    }
}
