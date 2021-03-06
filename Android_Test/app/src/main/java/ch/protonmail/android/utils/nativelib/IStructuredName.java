// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_pgp.djinni

package ch.protonmail.android.utils.nativelib;

import java.util.concurrent.atomic.AtomicBoolean;
import javax.annotation.CheckForNull;
import javax.annotation.Nonnull;

public abstract class IStructuredName {
    @Nonnull
    public abstract String getFamily();

    @Nonnull
    public abstract String getGiven();

    @CheckForNull
    public static IStructuredName createInstance()
    {
        return CppProxy.createInstance();
    }

    private static final class CppProxy extends IStructuredName
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

        @Override
        public String getFamily()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getFamily(this.nativeRef);
        }
        private native String native_getFamily(long _nativeRef);

        @Override
        public String getGiven()
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_getGiven(this.nativeRef);
        }
        private native String native_getGiven(long _nativeRef);

        @CheckForNull
        public static native IStructuredName createInstance();
    }
}
